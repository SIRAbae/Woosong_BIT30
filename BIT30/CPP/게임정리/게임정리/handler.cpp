//handler.cpp
#include "std.h"

#define IP		"192.168.0.87"
#define PORT	7000

extern vector<MEMBER> g_memberlist;
int sock1;

void logmessage(int flag, const char* msg)
{
	if (flag == 1) //클라이언트 접속
		printf("[클라이언트 접속] %s\n", msg);
	else if (flag == 2)
		printf("[서버 연결 해제 해제] %s\n", msg);
}

void recvmessage(unsigned int sock, char* msg, int size)
{
	msg[size] = '\0';	//retval => 실제 수신데이터 크기
	printf("[수신데이터] %s\n", msg);
}



BOOL OnInitDialog(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	InitCommonControls();

	ui_GetControlHandle(hDlg);

	ui_InitListView(hDlg);

	wbclient_init();
	//서버 접속 요청
	sock1 = wbclient_start(IP,PORT);
	if (sock1 == 0)
		MessageBox(0, TEXT("연결 실패"), TEXT("알림"), MB_OK);
	//wbclient_init();

	return TRUE;
}

BOOL OnCommand(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	switch (LOWORD(wParam))
	{
	case IDCANCEL: OnIdCancel(hDlg);		break;
		//File >> Exit
	case ID_MENU_EXIT: OnExit(hDlg);		break;

	case ID_MENU_INCERT: OnInsert(hDlg); break;
	}
	return TRUE;

}


void OnIdCancel(HWND hDlg)
{
	EndDialog(hDlg, IDCANCEL);
}

void OnExit(HWND hDlg)
{
	EndDialog(hDlg, IDOK);
}

void OnInsert(HWND hDlg)
{
	MEMBER mem;
	BOOL b = ui_Insert(hDlg, &mem);
	if (b == FALSE)
	{
		MessageBox(NULL, TEXT("저장 취소"), TEXT("알림"), MB_OK);
		return;
	}

	//저장의 흐름
	g_memberlist.push_back(mem);

	ui_PrintAll(hDlg);
}
