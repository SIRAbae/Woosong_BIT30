//packet.h

//��Ŷ ����(APP �������� ����)

//Ŭ���̾�Ʈ => ����
#define PACK_MESSAGE		1

//���� => Ŭ���̾�Ʈ

#define ACK_MESSAGE			10	 //�̸�   SELECT




typedef struct tagMESSAGE
{
	int flage;      //PACK���� �߰� 
	TCHAR G_name[100];
}MESSAGE;


MESSAGE pack_Message(TCHAR* G_name);