//ui.cpp

#include "std.h"

HWND g_hListTeamView, g_hCombo1;
vector<ACCOUNT>* memberlist;


void ui_GetTeamCreateInfo(HWND hDlg,TCHAR* ac_id)
{
	GetDlgItemText(hDlg, IDC_COMBO1, ac_id, 30);
}

void ui_InitTeamListView(HWND hDlg)
{
	g_hListTeamView = GetDlgItem(hDlg, IDC_LIST1);
	LVCOLUMN COL;

	// 헤더를 추가한다.
	COL.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;
	COL.fmt = LVCFMT_LEFT;
	COL.cx = 50;
	COL.pszText = (TCHAR*)TEXT("계좌 ID");				// 첫 번째 헤더
	COL.iSubItem = 0;
	SendMessage(g_hListTeamView, LVM_INSERTCOLUMN, 0, (LPARAM)& COL);

	COL.cx = 90;
	COL.pszText = (TCHAR*)TEXT("고객 ID");			// 두 번째 헤더
	COL.iSubItem = 1;
	SendMessage(g_hListTeamView, LVM_INSERTCOLUMN, 1, (LPARAM)& COL);

	COL.cx = 50;
	COL.pszText = (TCHAR*)TEXT("등록일자");			// 두 번째 헤더
	COL.iSubItem = 2;
	SendMessage(g_hListTeamView, LVM_INSERTCOLUMN, 2, (LPARAM)& COL);
	COL.cx = 97;
	COL.pszText = (TCHAR*)TEXT("계좌 잔액");			// 두 번째 헤더
	COL.iSubItem = 3;
	SendMessage(g_hListTeamView, LVM_INSERTCOLUMN, 3, (LPARAM)& COL);
	COL.cx = 120;
	COL.pszText = (TCHAR*)TEXT("사용횟수");			// 두 번째 헤더
	COL.iSubItem = 4;
	SendMessage(g_hListTeamView, LVM_INSERTCOLUMN, 4, (LPARAM)& COL);

}

void ui_TeamListPrint(vector<ACCOUNT>* datalist, int size)
{
	ListView_DeleteAllItems(g_hListTeamView);
	//ListView_DeleteItem(hList, idx);

	for (int i = 0; i < size; i++)
	{
		ACCOUNT info = (*datalist)[i];
		//========================================
		ListTeamPrint(info, i);
		//=========================================
	}
}

void ListTeamPrint(ACCOUNT info, int idx)
{
	LVITEM LI;

	// 텍스트와 이미지를 가진 아이템들을 등록한다.
	LI.mask = LVIF_TEXT;

	LI.iItem = idx;
	LI.iSubItem = 0;
	TCHAR buf[20];
	wsprintf(buf, TEXT("%d"), info.ac_id);
	LI.pszText = buf;			// 첫 번째 아이템
	SendMessage(g_hListTeamView, LVM_INSERTITEM, 0, (LPARAM)& LI);

	LI.iSubItem = 1;
	wsprintf(buf, TEXT("%d"), info.member_id);
	LI.pszText = buf;			
	SendMessage(g_hListTeamView, LVM_INSERTITEM, 0, (LPARAM)& LI);
	
	LI.iSubItem = 2;
	LI.pszText = info.ac_money;
	SendMessage(g_hListTeamView, LVM_SETITEM, 0, (LPARAM)& LI);

	LI.iSubItem = 3;
	LI.pszText = info.ac_date;
	SendMessage(g_hListTeamView, LVM_SETITEM, 0, (LPARAM)& LI);

	LI.iSubItem = 4;
	LI.pszText = info.ac_count;
	SendMessage(g_hListTeamView, LVM_SETITEM, 0, (LPARAM)& LI);



}

void ui_GetSearchName(HWND hDlg, TCHAR* id)
{
	//*team_id = GetDlgItemInt(hDlg, IDC_EDIT2, 0, 0);
	GetDlgItemText(hDlg, IDC_COMBO1, id, 30);
}
int ui_getDataid(HWND hDlg)
{
	int num = GetDlgItemInt(hDlg, IDC_EDIT3, 0, 0);
	return num;
}


void ui_getData(HWND hDlg, TCHAR* member_name, TCHAR* member_gender, TCHAR* member_phone, TCHAR* member_date)
{
	//GetDlgItemText(hDlg, IDC_EDIT2, member_name, 20);
	//GetDlgItemText(hDlg, IDC_EDIT3, member_gender, 5);
	//GetDlgItemText(hDlg, IDC_EDIT4, member_phone, 40);
	//GetDlgItemText(hDlg, IDC_EDIT5, member_date, 30);
}


int ui_getID(HWND hDlg)
{
	int num = GetDlgItemInt(hDlg, IDC_EDIT3, 0, 0);
	return num;
}


void ui_GetHandle(HWND hDlg)
{
	g_hCombo1 = GetDlgItem(hDlg, IDC_COMBO1);
}

void ui_InitCombo(HWND hDlg)
{
	ui_GetHandle(hDlg);
	for (int i = 0; i <= 100; i++)
	{
		TCHAR temp[10];
		wsprintf(temp, TEXT("") );
		SendMessage(g_hCombo1, CB_ADDSTRING, 0, (LPARAM)temp);
	}

	/*SendMessage(g_hCombo, CB_ADDSTRING, 0, (LPARAM)TEXT("ID"));
	SendMessage(g_hCombo, CB_ADDSTRING, 0, (LPARAM)TEXT("이름"));
	SendMessage(g_hCombo, CB_ADDSTRING, 0, (LPARAM)TEXT("성별"));
	SendMessage(g_hCombo, CB_ADDSTRING, 0, (LPARAM)TEXT("전화번호"));*/
}
int ui_GetMemberSelectInfo(HWND hDlg)
{

	int sel = SendMessage(g_hCombo1, CB_GETCURSEL, 0, 0);

	return sel;
}
int ui_GetMemberSelectId(HWND hDlg)
{
	int e_id = GetDlgItemInt(hDlg, IDC_EDIT3, 0, 0);

	return e_id;
}