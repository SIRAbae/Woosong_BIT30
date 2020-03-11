//thread(스레드) client [WSP p.72]

//client.cpp

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
	//AF_INET 네트워크 주소
	//TCP 프로토콜로 통신할 때 SOCK_STREAM(소켓의 타입)
	// UDP 프로토콜로 통신할 때 SOCK_DGRAM을 사용(소켓의 타입0
	//성공하면 핸들 / 실패하면 INVALID_SOCKET 반환
	if (sock == INVALID_SOCKET)
		//https://chasers.tistory.com/entry/윈도기반-소켓함수와-리눅스관련-소켓함수-1
			//함수를 보면 맨위 SOCKET 함수의 반환형이 각각 다른걸알수있는데 
			//정수로 표현되는 소켓의 핸들 값을 지정하기 위해 정의된 자료형
	{
		printf("소켓 생성 실패 \n");
		return -1;

	}
	//2.서버 연결 요청
	SOCKADDR_IN serveraddr = { 0 };
	serveraddr.sin_family = AF_INET;      //주소체계
	serveraddr.sin_port = htons(7000);      //네트워크 인지 안됨.
	serveraddr.sin_addr.s_addr = inet_addr("192.168.0.25");
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
		if (fgets(buf, sizeof(buf), stdin) == 0)      //엔터 쳤을때
			break;

		int length = strlen(buf);
		int retval = send(sock, buf, length, 0);
		if (retval == SOCKET_ERROR)
		{
			printf("송신 에러 \n");
			break;
		}

		char recvbuf[1024] = "";
		retval = recv(sock, recvbuf, sizeof(recvbuf), 0);
		if (retval == -1 || retval == 0)
			break;

		recvbuf[retval] = '\0';
		printf("수신 데이터 : %s \n", recvbuf);


		closesocket(sock);   //소켓 종료
	}

	//=============================

	WSACleanup();

	return 0;
}