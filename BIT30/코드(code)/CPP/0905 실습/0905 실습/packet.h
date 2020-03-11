//packet.h

//패킷 정의(APP 프로토콜 정의)

//클라이언트 => 서버
#define PACK_MESSAGE		1

//서버 => 클라이언트

#define ACK_MESSAGE			10	 //이름   SELECT




typedef struct tagMESSAGE
{
	int flage;      //PACK정의 추가 
	TCHAR G_name[100];
}MESSAGE;


MESSAGE pack_Message(TCHAR* G_name);