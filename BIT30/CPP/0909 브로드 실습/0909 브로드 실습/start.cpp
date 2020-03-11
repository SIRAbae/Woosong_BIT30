//start.cpp
#include "std.h"
#define RECVPORT  7000

CRITICAL_SECTION g_cs;
int main()
{
	InitializeCriticalSection(&g_cs);

	if (wbcommon_init() == 0)
	{
		printf("소켓 라이브러리 초기화 에러\n");
		return -1;
	}
	wbrecvber_start(RECVPORT);
	wbsenderbr_start(RECVPORT);
	while (1)
	{
		EnterCriticalSection(&g_cs);

		char buf[BUFSIZE + 1];
		// 데이터 입력
		if (fgets(buf, BUFSIZE + 1, stdin) == NULL)
			break;

		if (strlen(buf) == 0)
			break;

		int retval =wbsenderbr_senddata(buf,strlen(buf));
		if (retval == 0)
			continue;

		printf("%d바이트를 보냈습니다.\n", retval);

		LeaveCriticalSection(&g_cs);
		Sleep(1);
	}
	wbsenderbr_close();

	wbcommon_exit();

	DeleteCriticalSection(&g_cs);

	return 0;

}