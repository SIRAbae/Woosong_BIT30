//IP주소변환

#include <WinSock2.h>            //소켓 API 함수의 선언부
#pragma comment(lib,"ws_2_32.lib")   //소켓 API 함수의 구현부
#include<stdio.h>


int main(int arge, char* arv[])
{
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		printf("윈도우 소켓 초기화 실패!\n");

			return -1;
	}

	printf("윈도우 소켓 초기화 실패!\n");

	return -1;


	//===========================================================
	//문자열 주소 ==> 정수의 주소로 변환
	char ipaddr[20] = "230.00.12.5";
	printf("IP문자열 : %s\n", ipaddr);

	int numaddr = inet_addr(ipaddr);
	printf("IP 정수 : %x\n", numaddr);
	//---------------------------------------------------------
	IN_ADDR in_addr;
	in_addr,s_addr = numaddr; // inet_addr(ipaddr)
	printf("IP 정수 => 문자열 주소 = %s\n", inet_ntoa(in_addr));

	WSACleanup();
	return 0;

	//문자열 주소 출력
}