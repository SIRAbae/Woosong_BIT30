// �ҽ�.cpp

// ���� ����ڵ� �ҽ� sample
#include "wbserver.h"
#include <stdio.h>

extern unsigned int handle;

#define SERVER_PORT 7000

// flag 0 : Ŭ���̾�Ʈ ����
void logmessage(int flag, const char* msg) {

	if (flag == 1)   // Ŭ���̾�Ʈ ����
		printf("[Ŭ���̾�Ʈ ����] %s\n", msg);
	else if (flag == 2)
		printf("[Ŭ���̾�Ʈ ����] %s\n", msg);

}

void recvmessage(char* msg, int size) {


	msg[size] = '\0';   // retval => ���� ���ŵ����� ũ��
	printf("[���ŵ�����] %s\n", msg);

}

int main() {

	// 1. ������ ����ϱ� ���� �ݵ�� ���� �ʱ�ȭ �Լ� ȣ��
	if (wbserver_init() == 0)
	{

		printf("������ ���� �ʱ�ȭ ����!\n");
		return 0;
	}

	printf("������ ���� �ʱ�ȭ ����!\n");

	// ===================================================

	// 2. ���� ���� ����
	if (wbserver_start(SERVER_PORT) == 0)
	{
		printf("���� ���� ���� ����!\n");
		return -1;

	}
	printf("���� ���� ���� ����!\n");

	WaitForSingleObject((HANDLE)handle, INFINITE);
	// ===================================================

	// N. ������ ��������ϱ� ���� �ݵ�� ���α׷� ����� ȣ��
	wbserver_exit();

	return 0;
}