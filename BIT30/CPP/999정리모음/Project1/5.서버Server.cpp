//5.서버Server.cpp
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
		printf("윈도우 소켓 초기화 실패 \n");
		return -1;
	}
	printf("윈도우 소켓 초기화 성공 \n");
	//=============================
	//1. 소켓생성
	SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sock == INVALID_SOCKET)
	{
		printf("소켓 생성 실패 \n");
		return -1;

	}
	//2.서버 연결 요청
	SOCKADDR_IN serveraddr = { 0 };
	serveraddr.sin_family = AF_INET;      //주소체계
	serveraddr.sin_port = htons(7000);      //네트워크 인지 안됨.
	serveraddr.sin_addr.s_addr = inet_addr("192.168.0.52");
	int retval = connect(sock, (SOCKADDR*)& serveraddr, sizeof(serveraddr));
	if (retval == SOCKET_ERROR)
	{
		printf("연결 실패 \n");
		return -1;
	}
	printf("연결 성공\n");

	while (1)
	{
		char buf[1024] = "";
		printf(">>");
		if (fgets(buf, sizeof(buf), stdin) == NULL)      //엔터 쳤을때
			break;

		int length = strlen(buf);
		int retval = send(sock, buf, length, 0);
		if (retval == SOCKET_ERROR)
		{
			printf("송신 에러 \n");
			break;
		}
		closesocket(sock);   //소켓 종료
	}

	//=============================

	WSACleanup();

	return 0;
}