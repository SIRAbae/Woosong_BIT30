//1.환경구축하지 (기본)

//#define _WINSOCK_DEPRECATED_NOWARNINGS
#include <WinSock2.h>            //소켓 API 함수의 선언부
#pragma comment(lib,"ws2_32.lib")   //소켓 API 함수의 구현부
#include<stdio.h>
#pragma warning(disable : 4996)



int main(int arge, char* arv[])
{

	WSADATA wsa; //초기화
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		printf("윈도우 소켓 초기화 실패!\n");

		return -1;
	}

	

	printf("윈도우 소켓 초기화 성공!\n");
	


	
	WSACleanup();
	return 0;

	//문자열 주소 출력
}