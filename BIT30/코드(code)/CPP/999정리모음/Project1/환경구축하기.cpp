//IP주소변환

#include<WinSock2.h>
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


	
	WSACleanup();
	return 0;

	//문자열 주소 출력
}