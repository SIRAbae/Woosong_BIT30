//3.����Ʈ����.cpp

//#define _WINSOCK_DEPRECATED_NOWARNINGS
#include <WinSock2.h>            //���� API �Լ��� �����
#pragma comment(lib,"ws2_32.lib")   //���� API �Լ��� ������
#include<stdio.h>
#pragma warning(disable : 4996)

int main(int arge, char* arv[])
{
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		printf("������ ���� �ʱ�ȭ ����!\n");

		return -1;
	}

	unsigned short us = 0x1234;
	unsigned long ul = 0x12345678;

	//ȣ��Ʈ ����Ʈ�� ��Ʈ��ũ ����Ʈ�� ��ȯ�Ѵ�.
	printf("0x%08X = > 0x%08X\n", us, htons(us));
	printf("0x%08X = > 0x%08X\n", ul, htonl(ul));

	unsigned short nus = htons(us);
	unsigned long nul = htonl(ul);

	//ȣ��Ʈ ����Ʈ�� ��Ʈ��ũ ����Ʈ�� ��ȯ�Ѵ�.
	printf("0x%08X = > 0x%08X\n", nus, htons(nus));
	printf("0x%08X = > 0x%08X\n", nul, htonl(nul));




	WSACleanup();
	return 0;

	//���ڿ� �ּ� ���
}