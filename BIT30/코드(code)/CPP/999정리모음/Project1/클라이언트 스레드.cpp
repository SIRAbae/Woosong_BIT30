//Client.cpp : page27
//IPv4 주소 . . . . . . . . . : 192.168.0.34
#include <WinSock2.h>				//소켓 API 함수의 선언부 
#pragma comment(lib, "ws2_32.lib")	//소켓 API 함수의 구현부
#include <stdio.h>
#include <process.h>  // 스레드와 프로세스 작업에 쓰이는 헤더 파일
#pragma warning(disable : 4996)

int recvn(SOCKET s, char* buf, int len, int flags)
{
	int received;
	char* ptr = buf;
	int left = len;

	while (left > 0)
	{
		received = recv(s, ptr, left, flags);
		if (received == SOCKET_ERROR)
			return SOCKET_ERROR;
		else if (received == 0)
			break;
		left -= received;
		ptr += received;
	}
	return (len - left);
}

unsigned int __stdcall com_thread(void* value)
{
	SOCKET sock = (SOCKET)value;

	while (1)
	{
		char recvbuf[1024] = "";
		//===================== ServerCode Copy=====================
		//int recvdata(SOCKET sock, char *buf, int size)
		int size1;
		int retval = recvn(sock, (char*)& size1, sizeof(int), 0);
		if (retval == SOCKET_ERROR || retval == 0)	// -1
			return 0;

		retval = recvn(sock, recvbuf, size1, 0);
		if (retval == SOCKET_ERROR || retval == 0)	// -1
			return 0;
		//===========================================================
		printf("[수신 데이터 ] %s\n", recvbuf);

	}

	return 0;
}

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
	SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sock == INVALID_SOCKET)
	{
		printf("소켓 생성 실패\n");
		return -1;
	}

	//2. 서버 연결 요청
	SOCKADDR_IN serveraddr = { 0 };
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(7000);		//네트웤 인지 안된다.
	serveraddr.sin_addr.s_addr = inet_addr("192.168.0.39");//"127.0.0.1"

	int retval = connect(sock, (SOCKADDR*)& serveraddr, sizeof(serveraddr));
	if (retval == SOCKET_ERROR)
	{
		printf("연결 실패\n");
		return -1;
	}
	printf("연결 성공\n");

	unsigned int h;
	h = _beginthreadex(0, 0, com_thread, (void*)sock, 0, 0);
	CloseHandle((HANDLE)h);

	while (1)
	{
		char buf[1024] = "";
		printf(">> ");
		if (fgets(buf, sizeof(buf), stdin) == '\0') //엔터
			break;

		int length = strlen(buf) + 1;
		send(sock, (char*)& length, sizeof(int), 0);
		send(sock, buf, length, 0);
		if (retval == SOCKET_ERROR)
		{
			printf("송신 에러\n");
			break;
		}
	}

	closesocket(sock);		//소켓 종료 


	//==================================================
	WSACleanup();
	return 0;
}