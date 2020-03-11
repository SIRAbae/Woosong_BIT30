//ui.cpp

#include "std.h"

HWND g_hListTeamView;

void ui_GetTeamCreateInfo(HWND hDlg, int* team_id, TCHAR* team_name)
{
	//*team_id = GetDlgItemInt(hDlg, IDC_EDIT1, 0, 0);
	//GetDlgItemText(hDlg, IDC_EDIT2, team_name, 20);
}

void ui_InitTeamListView(HWND hDlg)
{
	g_hListTeamView = GetDlgItem(hDlg, IDC_LIST1);
	LVCOLUMN COL;

	// 헤더를 추가한다.
	COL.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;
	COL.fmt = LVCFMT_LEFT;
	COL.cx = 100;
	COL.pszText = (LPWSTR)TEXT("조ID");				// 첫 번째 헤더
	COL.iSubItem = 0;
	SendMessage(g_hListTeamView, LVM_INSERTCOLUMN, 0, (LPARAM)& COL);

	COL.pszText = (LPWSTR)TEXT("조명");			// 두 번째 헤더
	COL.iSubItem = 1;
	SendMessage(g_hListTeamView, LVM_INSERTCOLUMN, 1, (LPARAM)& COL);

}

void ui_TeamListPrint(vector<TEAM>* datalist, int size)
{
	ListView_DeleteAllItems(g_hListTeamView);
	//ListView_DeleteItem(hList, idx);

	for (int i = 0; i < size; i++)
	{
		TEAM info = (*datalist)[i];
		//========================================
		ListTeamPrint(info, i);
		//=========================================
	}
}

void ListTeamPrint(TEAM info, int idx)
{
	LVITEM LI;

	// 텍스트와 이미지를 가진 아이템들을 등록한다.
	LI.mask = LVIF_TEXT;

	LI.iItem = idx;
	LI.iSubItem = 0;
	TCHAR buf[20];
	wsprintf(buf, TEXT("%d"), info.team_id);
	LI.pszText = buf;			// 첫 번째 아이템
	SendMessage(g_hListTeamView, LVM_INSERTITEM, 0, (LPARAM)& LI);

	LI.iSubItem = 1;
	LI.pszText = info.team_name;
	SendMessage(g_hListTeamView, LVM_SETITEM, 0, (LPARAM)& LI);
}

/*
void ui_GetHandle(HWND hDlg)
{
	g_hListView = GetDlgItem(hDlg, IDC_LIST1);
}

void ui_SetListViewColumnHeader(HWND hDlg)
{
	LVCOLUMN COL;

	// 헤더를 추가한다.
	COL.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;
	COL.fmt = LVCFMT_LEFT;
	COL.cx = 150;
	COL.pszText = TEXT("이름");				// 첫 번째 헤더
	COL.iSubItem = 0;
	SendMessage(g_hListView, LVM_INSERTCOLUMN, 0, (LPARAM)&COL);

	COL.pszText = TEXT("PID");			// 두 번째 헤더
	COL.iSubItem = 1;
	SendMessage(g_hListView, LVM_INSERTCOLUMN, 1, (LPARAM)&COL);
}



*/