//Ŭ���̾�Ʈ Client.cpp
//#difine
#include <WinSock2.h>            //���� API �Լ��� �����
#pragma comment(lib,"ws2_32.lib")   //���� API �Լ��� ������
#include<stdio.h>
#pragma warning(disable : 4996)



int main(int arge, char* arv[])
{
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		printf("������ ���� �ʱ�ȭ ����!\n");

		return -1;
	}



	printf("������ ���� �ʱ�ȭ ����!\n");

	//==============================================
	SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);//Ŭ���̾�Ʈ�� ������ ���ƾ� �Ѵ�.
	if (sock == INVALID_SOCKET)
	{
		printf(" ���� ���� ����!\n");

		return -1;
	}

	//2.�������� ��û
	SOCKADDR_IN serveraddr = { 0 };
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(7000); // ��Ʈ�p ���� �ȵȴ�.
	serveraddr.sin_addr.s_addr = inet_addr("192.168.0.52"); //INADDR_ANY--���� pc�� �ּҰ� 
	
	int retval = connect(sock, (SOCKADDR*)& serveraddr, sizeof(serveraddr));
	if (sock == SOCKET_ERROR)
	{
		printf(" ���� ���� ����!\n");

		return -1;
	}
	
	printf(" ���� ���� ����!\n");
	
	WSACleanup();
	return 0;

	//���ڿ� �ּ� ���
}