//packet.h

//��Ŷ ����(APP �������� ����)

//Ŭ���̾�Ʈ => ����
#define PACK_INSERT		1
#define PACK_SELECT		2
#define PACK_UPDATE		3
#define PACK_DELETE		4

//��Ŷ ����ü 
typedef struct tagINSERT
{
	int flage;		//PACK���� �߰� 
	TCHAR id[20];
	TCHAR pw[20];
	TCHAR name[20];
	int age;
	TCHAR phone[20];
}INSERT;

typedef struct tagSELECT
{
	int flage;		//PACK���� �߰� 
	TCHAR name[20];
}SELECT;

typedef struct tagUPDATE
{
	int flage;		//PACK���� �߰� 
	TCHAR name[20];
	int age;
	TCHAR phone[20];
}UPDATE;


INSERT pack_Insert(TCHAR* id, TCHAR* pw, TCHAR* name, TCHAR* phone, int age);
SELECT pack_Select(TCHAR* name);
UPDATE pack_Update(TCHAR* name, TCHAR* phone, int age);
SELECT pack_Delete(TCHAR* name);