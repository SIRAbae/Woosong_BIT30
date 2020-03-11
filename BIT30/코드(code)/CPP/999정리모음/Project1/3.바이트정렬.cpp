//3.바이트정렬.cpp

//#define _WINSOCK_DEPRECATED_NOWARNINGS
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

	unsigned short us = 0x1234;
	unsigned long ul = 0x12345678;

	//호스트 바이트를 네트워크 바이트로 변환한다.
	printf("0x%08X = > 0x%08X\n", us, htons(us));
	printf("0x%08X = > 0x%08X\n", ul, htonl(ul));

	unsigned short nus = htons(us);
	unsigned long nul = htonl(ul);

	//호스트 바이트를 네트워크 바이트로 변환한다.
	printf("0x%08X = > 0x%08X\n", nus, htons(nus));
	printf("0x%08X = > 0x%08X\n", nul, htonl(nul));




	WSACleanup();
	return 0;

	//문자열 주소 출력
}