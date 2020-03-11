//IP주소변환

#include <WinSock2.h>            //소켓 API 함수의 선언부
#pragma comment(lib,"ws2_32.lib")   //소켓 API 함수의 구현부
#include<stdio.h>




int main(int arge, char* arv[])
{
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		printf("윈도우 소켓 초기화 실패!\n");

		return -1;
	}



	printf("윈도우 소켓 초기화 성공!\n");

	//======================================================
	
	
	//1. 소켓 생성
	SOCKET listenSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	//     소켓의 핸들
	if (listenSock == INVALID_SOCKET)
	{
		printf("윈도우 소켓 생성 실패!\n");
	
		return -1;
	}

	//2.주소 할당
	SOCKADDR_IN serveraddr = { 0 };
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(7000); // 네트웤 인지 안된다.
	serveraddr.sin_addr.s_addr = htonl(INADDR_ANY); //INADDR_ANY--현재 pc의 주소값 

	int retval = bind(listenSock, (SOCKADDR*)& serveraddr, sizeof(serveraddr));
	if (retval == SOCKET_ERROR)
	{
		printf("bin() 에러!\n");

		return -1;
	}

	//3. 개통
	retval = listen(listenSock, SOMAXCONN);
	//======================================================
	WSACleanup();
	return 0;

	//문자열 주소 출력
}