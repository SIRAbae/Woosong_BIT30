//IP�ּҺ�ȯ

#include <WinSock2.h>            //���� API �Լ��� �����
#pragma comment(lib,"ws2_32.lib")   //���� API �Լ��� ������
#include<stdio.h>




int main(int arge, char* arv[])
{
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		printf("������ ���� �ʱ�ȭ ����!\n");

		return -1;
	}



	printf("������ ���� �ʱ�ȭ ����!\n");

	//======================================================
	
	
	//1. ���� ����
	SOCKET listenSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	//     ������ �ڵ�
	if (listenSock == INVALID_SOCKET)
	{
		printf("������ ���� ���� ����!\n");
	
		return -1;
	}

	//2.�ּ� �Ҵ�
	SOCKADDR_IN serveraddr = { 0 };
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(7000); // ��Ʈ�p ���� �ȵȴ�.
	serveraddr.sin_addr.s_addr = htonl(INADDR_ANY); //INADDR_ANY--���� pc�� �ּҰ� 

	int retval = bind(listenSock, (SOCKADDR*)& serveraddr, sizeof(serveraddr));
	if (retval == SOCKET_ERROR)
	{
		printf("bin() ����!\n");

		return -1;
	}

	//3. ����
	retval = listen(listenSock, SOMAXCONN);
	//======================================================
	WSACleanup();
	return 0;

	//���ڿ� �ּ� ���
}