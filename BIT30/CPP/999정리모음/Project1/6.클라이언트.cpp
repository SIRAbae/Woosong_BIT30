//클라이언트 Client.cpp
//#difine
#include <WinSock2.h>            //소켓 API 함수의 선언부
#pragma comment(lib,"ws2_32.lib")   //소켓 API 함수의 구현부
#include<stdio.h>
#pragma warning(disable : 4996)



int main(int arge, char* arv[])
{
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		printf("윈도우 소켓 초기화 실패!\n");

		return -1;
	}



	printf("윈도우 소켓 초기화 성공!\n");

	//==============================================
	SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);//클라이언트가 서버와 같아야 한다.
	if (sock == INVALID_SOCKET)
	{
		printf(" 소켓 생성 실패!\n");

		return -1;
	}

	//2.서버연결 요청
	SOCKADDR_IN serveraddr = { 0 };
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(7000); // 네트웤 인지 안된다.
	serveraddr.sin_addr.s_addr = inet_addr("192.168.0.52"); //INADDR_ANY--현재 pc의 주소값 
	
	int retval = connect(sock, (SOCKADDR*)& serveraddr, sizeof(serveraddr));
	if (sock == SOCKET_ERROR)
	{
		printf(" 소켓 생성 실패!\n");

		return -1;
	}
	
	printf(" 소켓 생성 생성!\n");
	
	WSACleanup();
	return 0;

	//문자열 주소 출력
}