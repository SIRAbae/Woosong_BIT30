//1.ȯ�汸������ (�⺻)

//#define _WINSOCK_DEPRECATED_NOWARNINGS
#include <WinSock2.h>            //���� API �Լ��� �����
#pragma comment(lib,"ws2_32.lib")   //���� API �Լ��� ������
#include<stdio.h>
#pragma warning(disable : 4996)



int main(int arge, char* arv[])
{

	WSADATA wsa; //�ʱ�ȭ
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