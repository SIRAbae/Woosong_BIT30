//5-2서버server.cpp
//#define _WINSOCK_DEPRECATED_NOWARNINGS
#include <WinSock2.h>            //소켓 API 함수의 선언부
#pragma comment(lib,"ws2_32.lib")   //소켓 API 함수의 구현부
#include<stdio.h>
#pragma warning(disable : 4996)



int main()
{
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		printf("윈도우 소켓 초기화 실패\n");
		return -1;
	}
	printf("윈도우 소켓 초기화 성공\n");
	//=================================================

	//1. 소켓 생성
	SOCKET listenSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (listenSock == INVALID_SOCKET)	//-1
	{
		printf("소켓 생성 실패\n");
		return -1;
	}

	//2. 주소 할당
	SOCKADDR_IN serveraddr = { 0 };
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(7000);		//네트웤 인지 안된다.
	serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
	int retval = bind(listenSock, (SOCKADDR*)& serveraddr, sizeof(serveraddr));
	if (retval == SOCKET_ERROR)
	{
		printf("bid()에러\n");
		return -1;
	}

	//3. 개통
	retval = listen(listenSock, SOMAXCONN);
	if (retval == SOCKET_ERROR)
	{
		printf("listen()에러\n");
		return -1;
	}
	//=========================== INIT CODE의 END ================

	while (1)
	{
		//1. 접속처리
		SOCKADDR_IN clientaddr;
		int addrlen = sizeof(clientaddr);	//반드시 초기화....
		SOCKET clientSock = accept(listenSock, (SOCKADDR*)& clientaddr, &addrlen);
		if (clientSock == INVALID_SOCKET)
		{
			printf("클라이언트 접속 실패\n");
			continue;
		}
		//===== 클라이언트 접속 ============================
		//2. 클라이언트 정보 출력 
		printf(">>클라이언트 접속 : %s:%d\n",
			inet_ntoa(clientaddr.sin_addr), ntohs(clientaddr.sin_port));

		while (1)
		{
			char buf[1024];
			retval = recv(clientSock, buf, sizeof(buf), 0);
			if (retval == SOCKET_ERROR)	// -1
			{
				printf("수신 에러\n");
				break;
			}
			else if (retval == 0)
			{
				printf("상대방이 소켓을 닫은 경우\n");
				break;
			}
			else
			{
				buf[retval] = '\0';	//retval => 실제 수신데이터 크기
				printf("[%s:%d] %s\n",
					inet_ntoa(clientaddr.sin_addr),
					ntohs(clientaddr.sin_port), buf);
			}
		}
		closesocket(clientSock);
		printf(">>클라이언트 접속 해제 : %s:%d\n",
			inet_ntoa(clientaddr.sin_addr), ntohs(clientaddr.sin_port));
	}
	//==================================================
	WSACleanup();
	return 0;
}