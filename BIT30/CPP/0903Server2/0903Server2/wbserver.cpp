//wbserver.cpp
#include <stdio.h>
#include <process.h> //_begin_thread
#include <vector>
#include "wbserver.h"
#pragma warning(disable:4996)
using namespace std;

static SOCKET listenSock;
unsigned int handle;
vector<SOCKET> clientlist;

//약속된 함수(함수 선언) =======================================
void logmessage(int flag, const char* msg);
void recvmessage(char* msg, int size);
//===================================================

int wbserver_init()
{
	WSADATA wsa; //원속 초기화  -------원속: 인터넷 접속 프로그램
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
		// MAKEWORD(버전 정보)
		return 0;
	return 1;
}

void wbserver_exit()
{
	WSACleanup(); //소켓 종료
}

int wbserver_start(int port)
{
	//1. 소켓 생성
	listenSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	//AF_INET 네트워크 주소
	//TCP 프로토콜로 통신할 때 SOCK_STREAM(소켓의 타입)
	// UDP 프로토콜로 통신할 때 SOCK_DGRAM을 사용(소켓의 타입0
	//성공하면 핸들 / 실패하면 INVALID_SOCKET 반환
	if (listenSock == INVALID_SOCKET)   //-1
	{
		//https://chasers.tistory.com/entry/윈도기반-소켓함수와-리눅스관련-소켓함수-1
			//함수를 보면 맨위 SOCKET 함수의 반환형이 각각 다른걸알수있는데 
			//정수로 표현되는 소켓의 핸들 값을 지정하기 위해 정의된 자료형
		return 0;
	}

	//2. 주소 할당 page 24
	SOCKADDR_IN serveraddr = { 0 };			//[ title 소켓 구조체 ]  IPv4주소체계에서 사용하는 구조체 
	serveraddr.sin_family = AF_INET;		//주소체계
	serveraddr.sin_port = htons(port);      //네트웤 인지 안된다. / 지역포트번호
	serveraddr.sin_addr.s_addr = htonl(INADDR_ANY); // INADDR_ANY라는 이름의 상수를 통해서 서버의 IP주소를 할당
	//호스트 바이트 정렬 방식의 4바이트 데이터를 네트워크 바이트 정렬 방식으로 변환

	int retval = bind(listenSock, (SOCKADDR*)& serveraddr, sizeof(serveraddr));
	//serveraddr 구조체 변수를 사용하여 대기 소켓(listenSock)을 설정한 값으로 설정한다.
	if (retval == SOCKET_ERROR)
	{
		return 0;
	}

	//3. 개통
	retval = listen(listenSock, SOMAXCONN);
	// 대기 소켓(listenSock)을 클라이언트 접속이 성공하도록 접속 대기 큐를 만들어 
	//최대개수(SOMAXCONN)의 클라이언트가 동시 접속할 수 있도록 설정한다.
	if (retval == SOCKET_ERROR)
	{
		return 0;
	}
	//=======================수신 처리=======================
	handle = _beginthreadex(0, 0, listen_thread, 0, 0, 0);

	return 1;
}

unsigned int __stdcall listen_thread(void* value)
{
	while (1)
	{
		//1. 접속처리
		SOCKET clientsock = acceptclient();
		if (clientsock == 0)
			continue;

		//2. 클라이언트 정보 출력(사용자에게 전달)
		logmessage(1, clientsock);

		//저장
		clientlist.push_back(clientsock);

		//3. 통신 스레드 생성 page 36
		unsigned int h = _beginthreadex(0, 0, com_thread,
			(void*)clientsock, 0, 0);
		//com_thread ---에서----->(void*)clientsock로  소켓을 전달

		CloseHandle((HANDLE)h); //제어를 않할거면 소켓 닫기
	}
}



unsigned int __stdcall com_thread(void* value)  //데이터를 수신하고 사용자에게 전달하며 1대 다통신을 가능하게 한다.
{
	SOCKET clientsock = (SOCKET)value;
	while (1)
	{
		//3. 데이터 수신 
		char buf[1024] = "";
		int retval = recvdata(clientsock, buf, sizeof(buf));
		if (retval == 0)
			break;

		//4. 사용자에게 전달
		recvmessage(buf, retval);

		//4.크라이언트에게 재송신(1대 다통신)
		for (int i = 0; i < (int)clientlist.size(); i++)
		{
			SOCKET sock = clientlist[i];
			senddata(clientsock, buf, strlen(buf));

		}
		
	}

	//소켓 제거
	for (int i = 0; i < (int)clientlist.size(); i++)
	{
		SOCKET sock = clientlist[i];
		if(sock == clientsock)
		{ 
			clientlist.erase(clientlist.begin() + i);
		}
	}

	//클라이언트 접속 해제
	closesocket(clientsock);
	logmessage(2, clientsock);
	return 0;
}

SOCKET acceptclient()
{
	SOCKADDR_IN clientaddr;
	//page 24 접속대기
	int addrlen = sizeof(clientaddr);   //반드시 초기화....
	SOCKET clientSock = accept(listenSock, 
		(SOCKADDR*)& clientaddr, // 클라이언트의 정보 out param
		&addrlen				// 주소구조체형식의 크기, in(크기지정), out(초기화한크기반환) param
	);							// 통신소켓 생성: 원격 IP, 원격 포트 결정
	if (clientSock == INVALID_SOCKET)
		return 0;
	return clientSock;
}

void logmessage(int flag, SOCKET sock)
{
	char msg[100];
	SOCKADDR_IN clientaddr;
	int length = sizeof(clientaddr);
	getpeername(sock, (SOCKADDR*)& clientaddr, &length);
	sprintf_s(msg, "%s:%d", inet_ntoa(clientaddr.sin_addr), ntohs(clientaddr.sin_port));

	logmessage(1, msg);
}

int recvdata(SOCKET sock, char* buf, int size)
{
	int size1;
	int retval = recvn(sock, (char*)& size1, sizeof(int), 0);
	if (retval == SOCKET_ERROR || retval == 0)   // -1
		return 0;

	retval = recvn(sock, buf, size1, 0);
	if (retval == SOCKET_ERROR || retval == 0)   // -1
		return 0;
	return retval;

}

int senddata(SOCKET sock, char* buf, int size)
{
	send(sock, (char*)& size, sizeof(int), 0);

	return send (sock, buf, sizeof(int), 0);
}



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