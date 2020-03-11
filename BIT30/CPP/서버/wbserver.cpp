//wbserver.cpp
#include <stdio.h>
#include "wbserver.h"

static SOCKET listenSock;

//약속된 함수 =======================================
void logmessage(int flag, const char *msg);
void recvmessage(char *msg, int size);
//===================================================

int wbserver_init()
{
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
		return 0;
	return 1;
}

void wbserver_exit()
{
	WSACleanup();
}

int wbserver_start(int port)
{
	//1. 소켓 생성
	listenSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (listenSock == INVALID_SOCKET)	//-1
	{
		return 0;
	}

	//2. 주소 할당
	SOCKADDR_IN serveraddr = { 0 };
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(port);		//네트웤 인지 안된다.
	serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
	int retval = bind(listenSock, (SOCKADDR*)&serveraddr, sizeof(serveraddr));
	if (retval == SOCKET_ERROR)
	{
		return 0;
	}

	//3. 개통
	retval = listen(listenSock, SOMAXCONN);
	if (retval == SOCKET_ERROR)
	{
		return 0;
	}

	return 1;
}

void wbserver_run()
{
	while (1)
	{
		//1. 접속처리
		SOCKET clientsock = acceptclient();
		if (clientsock == 0)
			continue;

		//2. 클라이언트 정보 출력(사용자에게 전달)
		logmessage(1, clientsock);

//		while (1)
//		{
			//3. 데이터 수신 
			char buf[1024] = "";
			int retval = recvdata(clientsock, buf, sizeof(buf));
//			if (retval == 0)
//				break;

			//4. 사용자에게 전달
			recvmessage(buf, retval);			
//		}
		//클라이언트 접속 해제
		closesocket(clientsock);
		logmessage(2, clientsock); 
	}
}

SOCKET acceptclient()
{	
	SOCKADDR_IN clientaddr;
	int addrlen = sizeof(clientaddr);	//반드시 초기화....
	SOCKET clientSock = accept(listenSock, (SOCKADDR*)&clientaddr, &addrlen);
	if (clientSock == INVALID_SOCKET)
		return 0;
	return clientSock;
}

void logmessage(int flag, SOCKET sock)
{
	char msg[100];
	SOCKADDR_IN clientaddr;
	int length = sizeof(clientaddr);
	getpeername(sock, (SOCKADDR*)&clientaddr, &length);
	sprintf_s(msg, "%s:%d", inet_ntoa(clientaddr.sin_addr), ntohs(clientaddr.sin_port));
	
	logmessage(1, msg);
}

int recvdata(SOCKET sock, char *buf, int size)
{
	int retval = recv(sock, buf, size, 0);
	if (retval == SOCKET_ERROR || retval == 0)	// -1
		return 0;
	return retval;
}