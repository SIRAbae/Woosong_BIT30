//5-2����server.cpp
//#define _WINSOCK_DEPRECATED_NOWARNINGS
#include <WinSock2.h>            //���� API �Լ��� �����
#pragma comment(lib,"ws2_32.lib")   //���� API �Լ��� ������
#include<stdio.h>
#pragma warning(disable : 4996)



int main()
{
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		printf("������ ���� �ʱ�ȭ ����\n");
		return -1;
	}
	printf("������ ���� �ʱ�ȭ ����\n");
	//=================================================

	//1. ���� ����
	SOCKET listenSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (listenSock == INVALID_SOCKET)	//-1
	{
		printf("���� ���� ����\n");
		return -1;
	}

	//2. �ּ� �Ҵ�
	SOCKADDR_IN serveraddr = { 0 };
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(7000);		//��Ʈ�p ���� �ȵȴ�.
	serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
	int retval = bind(listenSock, (SOCKADDR*)& serveraddr, sizeof(serveraddr));
	if (retval == SOCKET_ERROR)
	{
		printf("bid()����\n");
		return -1;
	}

	//3. ����
	retval = listen(listenSock, SOMAXCONN);
	if (retval == SOCKET_ERROR)
	{
		printf("listen()����\n");
		return -1;
	}
	//=========================== INIT CODE�� END ================

	while (1)
	{
		//1. ����ó��
		SOCKADDR_IN clientaddr;
		int addrlen = sizeof(clientaddr);	//�ݵ�� �ʱ�ȭ....
		SOCKET clientSock = accept(listenSock, (SOCKADDR*)& clientaddr, &addrlen);
		if (clientSock == INVALID_SOCKET)
		{
			printf("Ŭ���̾�Ʈ ���� ����\n");
			continue;
		}
		//===== Ŭ���̾�Ʈ ���� ============================
		//2. Ŭ���̾�Ʈ ���� ��� 
		printf(">>Ŭ���̾�Ʈ ���� : %s:%d\n",
			inet_ntoa(clientaddr.sin_addr), ntohs(clientaddr.sin_port));

		while (1)
		{
			char buf[1024];
			retval = recv(clientSock, buf, sizeof(buf), 0);
			if (retval == SOCKET_ERROR)	// -1
			{
				printf("���� ����\n");
				break;
			}
			else if (retval == 0)
			{
				printf("������ ������ ���� ���\n");
				break;
			}
			else
			{
				buf[retval] = '\0';	//retval => ���� ���ŵ����� ũ��
				printf("[%s:%d] %s\n",
					inet_ntoa(clientaddr.sin_addr),
					ntohs(clientaddr.sin_port), buf);
			}
		}
		closesocket(clientSock);
		printf(">>Ŭ���̾�Ʈ ���� ���� : %s:%d\n",
			inet_ntoa(clientaddr.sin_addr), ntohs(clientaddr.sin_port));
	}
	//==================================================
	WSACleanup();
	return 0;
}