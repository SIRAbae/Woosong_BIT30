//IP�ּҺ�ȯ

#include<WinSock2.h>
#include<stdio.h>


int main(int arge, char* arv[])
{
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		printf("������ ���� �ʱ�ȭ ����!\n");

		return -1;
	}

	printf("������ ���� �ʱ�ȭ ����!\n");


	
	WSACleanup();
	return 0;

	//���ڿ� �ּ� ���
}