//packet.h

//패킷 정의(APP 프로토콜 정의)

//클라이언트 => 서버
#define PACK_INSERT		1
#define PACK_SELECT		2
#define PACK_UPDATE		3
#define PACK_DELETE		4

//패킷 구조체 
typedef struct tagINSERT
{
	int flage;		//PACK정의 추가 
	TCHAR id[20];
	TCHAR pw[20];
	TCHAR name[20];
	int age;
	TCHAR phone[20];
}INSERT;

typedef struct tagSELECT
{
	int flage;		//PACK정의 추가 
	TCHAR name[20];
}SELECT;

typedef struct tagUPDATE
{
	int flage;		//PACK정의 추가 
	TCHAR name[20];
	int age;
	TCHAR phone[20];
}UPDATE;


INSERT pack_Insert(TCHAR* id, TCHAR* pw, TCHAR* name, TCHAR* phone, int age);
SELECT pack_Select(TCHAR* name);
UPDATE pack_Update(TCHAR* name, TCHAR* phone, int age);
SELECT pack_Delete(TCHAR* name);