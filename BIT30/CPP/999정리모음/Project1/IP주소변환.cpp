//IP�ּҺ�ȯ

#include <WinSock2.h>            //���� API �Լ��� �����
#pragma comment(lib,"ws_2_32.lib")   //���� API �Լ��� ������
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

	return -1;


	//===========================================================
	//���ڿ� �ּ� ==> ������ �ּҷ� ��ȯ
	char ipaddr[20] = "230.00.12.5";
	printf("IP���ڿ� : %s\n", ipaddr);

	int numaddr = inet_addr(ipaddr);
	printf("IP ���� : %x\n", numaddr);
	//---------------------------------------------------------
	IN_ADDR in_addr;
	in_addr,s_addr = numaddr; // inet_addr(ipaddr)
	printf("IP ���� => ���ڿ� �ּ� = %s\n", inet_ntoa(in_addr));

	WSACleanup();
	return 0;

	//���ڿ� �ּ� ���
}