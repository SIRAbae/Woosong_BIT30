//wbserver.cpp
#include <stdio.h>
#include <process.h> //_begin_thread
#include <vector>
#include "wbserver.h"
#pragma warning(disable:4996)
using namespace std;

static SOCKET listenSock;
unsigned int handle;
vector<SOCKET> clientlist;

//��ӵ� �Լ�(�Լ� ����) =======================================
void logmessage(int flag, const char* msg);
void recvmessage(char* msg, int size);
//===================================================

int wbserver_init()
{
	WSADATA wsa; //���� �ʱ�ȭ  -------����: ���ͳ� ���� ���α׷�
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
		// MAKEWORD(���� ����)
		return 0;
	return 1;
}

void wbserver_exit()
{
	WSACleanup(); //���� ����
}

int wbserver_start(int port)
{
	//1. ���� ����
	listenSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	//AF_INET ��Ʈ��ũ �ּ�
	//TCP �������ݷ� ����� �� SOCK_STREAM(������ Ÿ��)
	// UDP �������ݷ� ����� �� SOCK_DGRAM�� ���(������ Ÿ��0
	//�����ϸ� �ڵ� / �����ϸ� INVALID_SOCKET ��ȯ
	if (listenSock == INVALID_SOCKET)   //-1
	{
		//https://chasers.tistory.com/entry/�������-�����Լ���-����������-�����Լ�-1
			//�Լ��� ���� ���� SOCKET �Լ��� ��ȯ���� ���� �ٸ��ɾ˼��ִµ� 
			//������ ǥ���Ǵ� ������ �ڵ� ���� �����ϱ� ���� ���ǵ� �ڷ���
		return 0;
	}

	//2. �ּ� �Ҵ� page 24
	SOCKADDR_IN serveraddr = { 0 };			//[ title ���� ����ü ]  IPv4�ּ�ü�迡�� ����ϴ� ����ü 
	serveraddr.sin_family = AF_INET;		//�ּ�ü��
	serveraddr.sin_port = htons(port);      //��Ʈ�p ���� �ȵȴ�. / ������Ʈ��ȣ
	serveraddr.sin_addr.s_addr = htonl(INADDR_ANY); // INADDR_ANY��� �̸��� ����� ���ؼ� ������ IP�ּҸ� �Ҵ�
	//ȣ��Ʈ ����Ʈ ���� ����� 4����Ʈ �����͸� ��Ʈ��ũ ����Ʈ ���� ������� ��ȯ

	int retval = bind(listenSock, (SOCKADDR*)& serveraddr, sizeof(serveraddr));
	//serveraddr ����ü ������ ����Ͽ� ��� ����(listenSock)�� ������ ������ �����Ѵ�.
	if (retval == SOCKET_ERROR)
	{
		return 0;
	}

	//3. ����
	retval = listen(listenSock, SOMAXCONN);
	// ��� ����(listenSock)�� Ŭ���̾�Ʈ ������ �����ϵ��� ���� ��� ť�� ����� 
	//�ִ밳��(SOMAXCONN)�� Ŭ���̾�Ʈ�� ���� ������ �� �ֵ��� �����Ѵ�.
	if (retval == SOCKET_ERROR)
	{
		return 0;
	}
	//=======================���� ó��=======================
	handle = _beginthreadex(0, 0, listen_thread, 0, 0, 0);

	return 1;
}

unsigned int __stdcall listen_thread(void* value)
{
	while (1)
	{
		//1. ����ó��
		SOCKET clientsock = acceptclient();
		if (clientsock == 0)
			continue;

		//2. Ŭ���̾�Ʈ ���� ���(����ڿ��� ����)
		logmessage(1, clientsock);

		//����
		clientlist.push_back(clientsock);

		//3. ��� ������ ���� page 36
		unsigned int h = _beginthreadex(0, 0, com_thread,
			(void*)clientsock, 0, 0);
		//com_thread ---����----->(void*)clientsock��  ������ ����

		CloseHandle((HANDLE)h); //��� ���ҰŸ� ���� �ݱ�
	}
}



unsigned int __stdcall com_thread(void* value)  //�����͸� �����ϰ� ����ڿ��� �����ϸ� 1�� ������� �����ϰ� �Ѵ�.
{
	SOCKET clientsock = (SOCKET)value;
	while (1)
	{
		//3. ������ ���� 
		char buf[1024] = "";
		int retval = recvdata(clientsock, buf, sizeof(buf));
		if (retval == 0)
			break;

		//4. ����ڿ��� ����
		recvmessage(buf, retval);

		//4.ũ���̾�Ʈ���� ��۽�(1�� �����)
		for (int i = 0; i < (int)clientlist.size(); i++)
		{
			SOCKET sock = clientlist[i];
			senddata(clientsock, buf, strlen(buf));

		}
		
	}

	//���� ����
	for (int i = 0; i < (int)clientlist.size(); i++)
	{
		SOCKET sock = clientlist[i];
		if(sock == clientsock)
		{ 
			clientlist.erase(clientlist.begin() + i);
		}
	}

	//Ŭ���̾�Ʈ ���� ����
	closesocket(clientsock);
	logmessage(2, clientsock);
	return 0;
}

SOCKET acceptclient()
{
	SOCKADDR_IN clientaddr;
	//page 24 ���Ӵ��
	int addrlen = sizeof(clientaddr);   //�ݵ�� �ʱ�ȭ....
	SOCKET clientSock = accept(listenSock, 
		(SOCKADDR*)& clientaddr, // Ŭ���̾�Ʈ�� ���� out param
		&addrlen				// �ּұ���ü������ ũ��, in(ũ������), out(�ʱ�ȭ��ũ���ȯ) param
	);							// ��ż��� ����: ���� IP, ���� ��Ʈ ����
	if (clientSock == INVALID_SOCKET)
		return 0;
	return clientSock;
}

void logmessage(int flag, SOCKET sock)
{
	char msg[100];
	SOCKADDR_IN clientaddr;
	int length = sizeof(clientaddr);
	getpeername(sock, (SOCKADDR*)& clientaddr, &length);
	sprintf_s(msg, "%s:%d", inet_ntoa(clientaddr.sin_addr), ntohs(clientaddr.sin_port));

	logmessage(1, msg);
}

int recvdata(SOCKET sock, char* buf, int size)
{
	int size1;
	int retval = recvn(sock, (char*)& size1, sizeof(int), 0);
	if (retval == SOCKET_ERROR || retval == 0)   // -1
		return 0;

	retval = recvn(sock, buf, size1, 0);
	if (retval == SOCKET_ERROR || retval == 0)   // -1
		return 0;
	return retval;

}

int senddata(SOCKET sock, char* buf, int size)
{
	send(sock, (char*)& size, sizeof(int), 0);

	return send (sock, buf, sizeof(int), 0);
}



int recvn(SOCKET s, char* buf, int len, int flags)
{
	int received;
	char* ptr = buf;
	int left = len;

	while (left > 0)
	{
		received = recv(s, ptr, left, flags);
		if (received == SOCKET_ERROR)
			return SOCKET_ERROR;

		else if (received == 0)
			break;

		left -= received;
		ptr += received;
	}

	return (len - left);
}