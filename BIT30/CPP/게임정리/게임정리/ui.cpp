//ui.cpp
#include "std.h"

HWND g_hList;		//IDC_LIST1
HWND g_button1, g_button2;
 vector<MEMBER> g_memberlist;

void ui_GetControlHandle(HWND hDlg)
{
	g_hList = GetDlgItem(hDlg, IDC_LIST1);
	/*g_button1 = GetDlgItem(hDlg, IDOK);
	g_button2 = GetDlgItem(hDlg, IDCANCEL);*/
	
}

void ui_InitListView(HWND hDlg)
{
	LVCOLUMN COL = { 0 };

	COL.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;
	COL.fmt = LVCFMT_LEFT;
	COL.cx = 100;
	COL.pszText = (LPWSTR)TEXT("I D");				    // 첫 번째 헤더
	COL.iSubItem = 0;
	SendMessage(g_hList, LVM_INSERTCOLUMN, 0, (LPARAM)& COL);

	COL.cx = 100;
	COL.pszText = (LPWSTR)TEXT("직 업");				// 
	COL.iSubItem = 1;
	SendMessage(g_hList, LVM_INSERTCOLUMN, 1, (LPARAM)& COL);

	COL.cx = 100;
	COL.pszText = (LPWSTR)TEXT("Level");				// 
	COL.iSubItem = 2;
	SendMessage(g_hList, LVM_INSERTCOLUMN, 2, (LPARAM)& COL);

	

	//// 위 4 개의 확장 스타일 모두 지정
	//ListView_SetExtendedListViewStyle(
	//	g_hList,
	//	LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES |
	//	LVS_EX_HEADERDRAGDROP);
}
/*
void ui_SetAddress(HWND hDlg, TCHAR* ip, int port)
{
	SetDlgItemText(hDlg, IDC_IPADDRESS1, ip);
	SetDlgItemInt(hDlg, IDC_EDIT7, port, 0);
}
*/
void ui_GetAddress(HWND hDlg, TCHAR* ip, int* port)
{
	GetDlgItemText(hDlg, IDC_IPADDRESS1, ip, sizeof(TCHAR) * 40);

}

BOOL ui_Insert(HWND hDlg, MEMBER* pmem)
{
	MEMBER member = { 0 };

	UINT ret = DialogBoxParam(GetModuleHandle(0),
		MAKEINTRESOURCE(IDD_DIALOG1), hDlg,
		InsertProc, (LPARAM)& member);

	if (ret == IDOK)
	{
		*pmem = member;
		return TRUE;
	}
	else					return FALSE;
}

void ui_PrintAll(HWND hDlg)
{
	int size = g_memberlist.size();
	SetDlgItemInt(hDlg, IDC_EDIT1, size, 0);
	//=================================================
	ListView_DeleteAllItems(g_hList); //아이템 모두 삭제

	for (int i = 0; i < (int)g_memberlist.size(); i++)
	{
		MEMBER mem = g_memberlist[i];
		// 텍스트와 이미지를 가진 아이템들을 등록한다.

		LVITEM LI;

		LI.mask = LVIF_TEXT;
		LI.iItem = i;
		LI.iSubItem = 0;
		LI.pszText = (LPWSTR)mem.id;			// 첫 번째 아이템
		SendMessage(g_hList, LVM_INSERTITEM, 0, (LPARAM)& LI);

		LI.iSubItem = 1;
		TCHAR temp[20];
		wsprintf(temp, TEXT("%s"), mem.job);
		LI.pszText = temp;
		SendMessage(g_hList, LVM_SETITEM, 0, (LPARAM)& LI);

		LI.iSubItem = 2;
		wsprintf(temp, TEXT("%d"), mem.level);
		LI.pszText = temp;
		SendMessage(g_hList, LVM_SETITEM, 0, (LPARAM)& LI);
	}
}

//void ui_SetButtonEnable(BOOL b1, BOOL b2, BOOL b3, BOOL b4, BOOL b5, BOOL b6)
//{
//	EnableWindow(g_button1, b1);
//	EnableWindow(g_button2, b2);
//	
//}