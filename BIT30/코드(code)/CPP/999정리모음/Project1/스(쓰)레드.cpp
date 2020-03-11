//thread(������) client [WSP p.72]

//client.cpp

#include <WinSock2.h>            //���� API �Լ��� �����
#pragma comment(lib,"ws2_32.lib")   //���� API �Լ��� ������
#include<stdio.h>
#pragma warning(disable : 4996)

int main()
{
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		printf("������ ���� �ʱ�ȭ ���� \n");
		return -1;
	}
	printf("������ ���� �ʱ�ȭ ���� \n");
	//=============================
	//1. ���ϻ���
	SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	//AF_INET ��Ʈ��ũ �ּ�
	//TCP �������ݷ� ����� �� SOCK_STREAM(������ Ÿ��)
	// UDP �������ݷ� ����� �� SOCK_DGRAM�� ���(������ Ÿ��0
	//�����ϸ� �ڵ� / �����ϸ� INVALID_SOCKET ��ȯ
	if (sock == INVALID_SOCKET)
		//https://chasers.tistory.com/entry/�������-�����Լ���-����������-�����Լ�-1
			//�Լ��� ���� ���� SOCKET �Լ��� ��ȯ���� ���� �ٸ��ɾ˼��ִµ� 
			//������ ǥ���Ǵ� ������ �ڵ� ���� �����ϱ� ���� ���ǵ� �ڷ���
	{
		printf("���� ���� ���� \n");
		return -1;

	}
	//2.���� ���� ��û
	SOCKADDR_IN serveraddr = { 0 };
	serveraddr.sin_family = AF_INET;      //�ּ�ü��
	serveraddr.sin_port = htons(7000);      //��Ʈ��ũ ���� �ȵ�.
	serveraddr.sin_addr.s_addr = inet_addr("192.168.0.25");
	int retval = connect(sock, (SOCKADDR*)& serveraddr, sizeof(serveraddr));
	if (retval == SOCKET_ERROR)
	{
		printf("���� ���� \n");
		return -1;
	}
	printf("���� ����\n");

	while (1)
	{
		char buf[1024] = "";
		printf(">>");
		if (fgets(buf, sizeof(buf), stdin) == 0)      //���� ������
			break;

		int length = strlen(buf);
		int retval = send(sock, buf, length, 0);
		if (retval == SOCKET_ERROR)
		{
			printf("�۽� ���� \n");
			break;
		}

		char recvbuf[1024] = "";
		retval = recv(sock, recvbuf, sizeof(recvbuf), 0);
		if (retval == -1 || retval == 0)
			break;

		recvbuf[retval] = '\0';
		printf("���� ������ : %s \n", recvbuf);


		closesocket(sock);   //���� ����
	}

	//=============================

	WSACleanup();

	return 0;
}