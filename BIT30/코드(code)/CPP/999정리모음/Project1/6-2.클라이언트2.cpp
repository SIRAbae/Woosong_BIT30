//client.cpp

#include <WinSock2.h>				 //���� API �Լ��� �����
#pragma comment(lib,"ws2_32.lib")	 //���� API �Լ��� ������
#include<stdio.h>
#include <process.h>  // ������� ���μ��� �۾��� ���̴� ��� ����
#pragma warning(disable : 4996)


int recvn(SOCKET s, char* buf, int len, int flags)
{
	int received; 
	char* ptr = buf;
	//ptr�� ���� ���ø����̼� ������ ������ġ
	int left = len;// len�� ���� ���� ũ���̴�.

	while (left > 0)
	{
		received = recv //received�� recv()�Լ��� ���� ����Ʈ ��
		(
			s, //��ż����� �ڵ�
			ptr, //���ø����̼� ������ ���� �ּ�
			left, //���� �ִ� ����Ʈ ��
			flags); 
		if (received == SOCKET_ERROR)
			return SOCKET_ERROR;
		else if (received == 0)
			break;
		left -= received;
		ptr += received;
	}
	return (len - left);
}

unsigned int __stdcall com_thread(void* value)
{
	SOCKET sock = (SOCKET)value;

	while (1)
	{
		char recvbuf[1024] = "";
		//===================== ServerCode Copy=====================
		//int recvdata(SOCKET sock, char *buf, int size)
		int size1;
		int retval = recvn(sock, (char*)& size1, sizeof(int), 0);
		if (retval == SOCKET_ERROR || retval == 0)	// -1
			return 0;

		retval = recvn(sock, recvbuf, size1, 0);
		if (retval == SOCKET_ERROR || retval == 0)	// -1
			return 0;
		//===========================================================
		printf("[���� ������ ] %s\n", recvbuf);

	}

	return 0;
}



int main()
{
	WSADATA wsa;  //���� �ʱ�ȭ  -------����: ���ͳ� ���� ���α׷�
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
		// MAKEWORD(���� ����)
	{
		printf("������ ���� �ʱ�ȭ ���� \n");
		return -1;
	}
	printf("������ ���� �ʱ�ȭ ���� \n");
	//=============================
	//1. ���ϻ���
	SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	//AF_INET ��Ʈ��ũ �ּ�
	//TCP �������ݷ� ����� �� SOCK_STREAM(������ Ÿ��)
	// UDP �������ݷ� ����� �� SOCK_DGRAM�� ���(������ Ÿ��0
	//�����ϸ� �ڵ� / �����ϸ� INVALID_SOCKET ��ȯ
	if (sock == INVALID_SOCKET)
		//https://chasers.tistory.com/entry/�������-�����Լ���-����������-�����Լ�-1
			//�Լ��� ���� ���� SOCKET �Լ��� ��ȯ���� ���� �ٸ��ɾ˼��ִµ� 
			//������ ǥ���Ǵ� ������ �ڵ� ���� �����ϱ� ���� ���ǵ� �ڷ���
	{
		printf("���� ���� ���� \n");
		return -1;

	}
	//2.���� ���� ��û
	SOCKADDR_IN serveraddr = { 0 };
	serveraddr.sin_family = AF_INET;      //�ּ�ü��
	serveraddr.sin_port = htons(7000);      //��Ʈ��ũ ���� �ȵ�.
	serveraddr.sin_addr.s_addr = inet_addr("192.168.0.25");//����  ip �ּ�
	int retval = connect(sock, (SOCKADDR*)& serveraddr, sizeof(serveraddr));
	if (retval == SOCKET_ERROR)
	{
		printf("���� ���� \n");
		return -1;
	}
	printf("���� ����\n");

	unsigned int h;
	h = _beginthreadex(0, 0, com_thread, (void*)sock, 0, 0);
	CloseHandle((HANDLE)h);

	while (1)
	{
		char buf[1024] = "";
		printf(">>");
		if (fgets(buf, sizeof(buf), stdin) == 0)      //���� ������
			break;

		int length = strlen(buf);
		int retval = send(sock, buf, length, 0);
		if (retval == SOCKET_ERROR)
		{
			printf("�۽� ���� \n");
			break;
		}

	}

	closesocket(sock);   //���� ����


//=============================

	WSACleanup();

	return 0;
}