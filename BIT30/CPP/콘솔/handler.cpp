//handler.cpp
#include "std.h"

#define IP		TEXT("192.168.0.52")
#define PORT	7000

BOOL OnInitDialog(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	InitCommonControls();

	ui_GetControlHandle(hDlg);

	ui_InitListView(hDlg);

	ui_SetAddress(hDlg, IP, PORT);

	return TRUE;
}

BOOL OnCommand(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	switch (LOWORD(wParam))
	{
	case IDCANCEL:		OnIdCancel(hDlg);		break;
	case IDC_BUTTON1:	OnConnect(hDlg);		break;
	case IDC_BUTTON2:   OnDisConnect(hDlg);		break;
	case IDC_BUTTON3:	OnInsert(hDlg);			break;
	case IDC_BUTTON4:	OnSelect(hDlg);			break;
	case IDC_BUTTON5:	OnUpdate(hDlg);			break;
	case IDC_BUTTON6:	OnDelete(hDlg);			break;
	}
	return TRUE;
}

void OnIdCancel(HWND hDlg)
{
	EndDialog(hDlg, IDCANCEL);
}

void OnConnect(HWND hDlg)
{
	TCHAR ip[40];
	int port;

	ui_GetAddress(hDlg, ip, &port);

	//辑滚 立加 夸没

}

void OnDisConnect(HWND hDlg)
{
	//辑滚 立加 秦力 夸没 
}

void OnInsert(HWND hDlg)
{
	TCHAR id[20], pw[20], name[20], phone[20];
	int age; 

	ui_GetInsertData(hDlg, id, pw, name, phone, &age);

//	wprintf(TEXT("%s,%s,%s,%d,%s\n"), id, pw, name, age, phone);
}

void OnSelect(HWND hDlg)
{
	TCHAR name[20];

	ui_GetName(hDlg, name);
}

void OnUpdate(HWND hDlg)
{
	TCHAR name[20], phone[20];
	int age;

	ui_GetUpdate(hDlg, name, phone, &age);
}

void OnDelete(HWND hDlg)
{
	TCHAR name[20];

	ui_GetName(hDlg, name);
}