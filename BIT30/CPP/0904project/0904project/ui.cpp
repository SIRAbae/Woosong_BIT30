//ui.cpp
#include "std.h"

HWND g_hList;		//IDC_LIST1
HWND g_button1, g_button2, g_button3, g_button4, g_button5, g_button6;

void ui_GetControlHandle(HWND hDlg)
{
	g_hList = GetDlgItem(hDlg, IDC_LIST1);
	g_button1 = GetDlgItem(hDlg, IDC_BUTTON3);
	g_button2 = GetDlgItem(hDlg, IDC_BUTTON4);
	g_button3 = GetDlgItem(hDlg, IDC_BUTTON5);
	g_button4 = GetDlgItem(hDlg, IDC_BUTTON2);
	g_button5 = GetDlgItem(hDlg, IDC_BUTTON6);
	g_button6 = GetDlgItem(hDlg, IDC_BUTTON7);
}

void ui_InitListView(HWND hDlg)
{
	LVCOLUMN COL = { 0 };

	COL.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;
	COL.fmt = LVCFMT_LEFT;
	COL.cx = 100;
	COL.pszText = TEXT("ID");				// ù ��° ���
	COL.iSubItem = 0;
	SendMessage(g_hList, LVM_INSERTCOLUMN, 0, (LPARAM)& COL);

	COL.cx = 100;
	COL.pszText = TEXT("PW");				// 
	COL.iSubItem = 1;
	SendMessage(g_hList, LVM_INSERTCOLUMN, 1, (LPARAM)& COL);

	COL.cx = 100;
	COL.pszText = TEXT("�̸�");				// 
	COL.iSubItem = 2;
	SendMessage(g_hList, LVM_INSERTCOLUMN, 2, (LPARAM)& COL);

	COL.cx = 100;
	COL.pszText = TEXT("����");				// 
	COL.iSubItem = 3;
	SendMessage(g_hList, LVM_INSERTCOLUMN, 3, (LPARAM)& COL);

	COL.cx = 100;
	COL.pszText = TEXT("��ȭ��ȣ");				// 
	COL.iSubItem = 4;
	SendMessage(g_hList, LVM_INSERTCOLUMN, 4, (LPARAM)& COL);

	// �� 4 ���� Ȯ�� ��Ÿ�� ��� ����
	ListView_SetExtendedListViewStyle(
		g_hList,
		LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES |
		LVS_EX_HEADERDRAGDROP);
}

void ui_SetAddress(HWND hDlg, TCHAR* ip, int port)
{
	SetDlgItemText(hDlg, IDC_IPADDRESS1, ip);
	SetDlgItemInt(hDlg, IDC_EDIT7, port, 0);
}

void ui_GetAddress(HWND hDlg, TCHAR* ip, int* port)
{
	GetDlgItemText(hDlg, IDC_IPADDRESS1, ip, sizeof(TCHAR) * 40);
	*port = GetDlgItemInt(hDlg, IDC_EDIT7, 0, 0);
}

void ui_GetInsertData(HWND hDlg, TCHAR* id, TCHAR* pw, TCHAR* name, TCHAR* phone, int* age)
{
	GetDlgItemText(hDlg, IDC_EDIT3, id, sizeof(TCHAR) * 20);
	GetDlgItemText(hDlg, IDC_EDIT4, pw, sizeof(TCHAR) * 20);
	GetDlgItemText(hDlg, IDC_EDIT5, name, sizeof(TCHAR) * 20);
	GetDlgItemText(hDlg, IDC_EDIT8, phone, sizeof(TCHAR) * 20);
	*age = GetDlgItemInt(hDlg, IDC_EDIT6, 0, 0);
}

void ui_GetName(HWND hDlg, TCHAR* name)
{
	GetDlgItemText(hDlg, IDC_EDIT5, name, sizeof(TCHAR) * 20);
}

void ui_GetUpdate(HWND hDlg, TCHAR* name, TCHAR* phone, int* age)
{
	GetDlgItemText(hDlg, IDC_EDIT5, name, sizeof(TCHAR) * 20);
	GetDlgItemText(hDlg, IDC_EDIT8, phone, sizeof(TCHAR) * 20);
	*age = GetDlgItemInt(hDlg, IDC_EDIT6, 0, 0);
}

void ui_SetButtonEnable(BOOL b1, BOOL b2, BOOL b3, BOOL b4, BOOL b5, BOOL b6)
{
	EnableWindow(g_button1, b1);
	EnableWindow(g_button2, b2);
	EnableWindow(g_button3, b3);
	EnableWindow(g_button4, b4);
	EnableWindow(g_button5, b5);
	EnableWindow(g_button6, b6);
}
