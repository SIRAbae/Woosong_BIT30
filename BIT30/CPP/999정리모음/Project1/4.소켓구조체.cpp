//4.소켓구조체.cpp
 //작동안함 참고만

//#define _WINSOCK_DEPRECATED_NOWARNINGS
#include <WinSock2.h>            //소켓 API 함수의 선언부
#pragma comment(lib,"ws2_32.lib")   //소켓 API 함수의 구현부
#include<stdio.h>
#pragma warning(disable : 4996)

typedef struct sockaddr
{
	u_short sa_family;		//2byte
	CHAR sa_data[14];		//14byte

} SOCKADDT, *PSOCKADDR, FAR *LPSOCKADDR;

typedef struct sockaddr_in
{
	short sin_family;		//2byte
	USHORT sin_port;		//2byte
	IN_ADDR sin_addr;		//4byte
	CHAR sin_zero[8];		//8byte

} SOCKADDT_IN, * PSOCKADDR_IN;


typedef struct in_addr
{
	union
	{
		struct
		{
			UCHAR s_b1, s_b2, s_b3, s_b4;
		} S_un_b;
	
		struct
		{
			USHORT s_w1, s_w2;
		} S_un_w;

		ULONG S_addr;
	} S_un;
};
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