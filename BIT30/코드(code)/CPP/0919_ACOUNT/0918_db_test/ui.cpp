//ui.cpp

#include "std.h"

HWND g_hListTeamView;
HWND g_combo1;

void ui_GetTeamCreateInfo(HWND hDlg, TCHAR*id)
{
	//*team_id = GetDlgItemInt(hDlg, IDC_EDIT2, 0, 0);
	GetDlgItemText(hDlg, IDC_COMBO1, id, 30);
}

void ui_GetSearchName(HWND hDlg, TCHAR*id)
{
	//*team_id = GetDlgItemInt(hDlg, IDC_EDIT2, 0, 0);
	GetDlgItemText(hDlg, IDC_COMBO1, id, 30);
}

void ui_GetAllInfo(HWND hDlg,int *id, TCHAR*name, TCHAR*phone, TCHAR*date,TCHAR*gender)
{
	*id = GetDlgItemInt(hDlg, IDC_EDIT2, 0, 0);
	GetDlgItemText(hDlg, IDC_EDIT3, name, 30);
	GetDlgItemText(hDlg, IDC_EDIT4, phone, 30);
	GetDlgItemText(hDlg, IDC_EDIT5, date, 50);
	GetDlgItemText(hDlg, IDC_EDIT6, gender, 30);
}

void ui_GetIDInfo(HWND hDlg, int *id)
{
	*id = GetDlgItemInt(hDlg, IDC_EDIT2, 0, 0);
	
}

void ui_InitTeamListView(HWND hDlg)
{
	g_hListTeamView = GetDlgItem(hDlg, IDC_LIST3);
	g_combo1 = GetDlgItem(hDlg, IDC_COMBO1);
	LVCOLUMN COL;

	// ����� �߰��Ѵ�.
	COL.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;
	COL.fmt = LVCFMT_LEFT;
	COL.cx = 50;
	COL.pszText = (LPWSTR)TEXT("ID");            // ù ��° ���
	COL.iSubItem = 0;
	SendMessage(g_hListTeamView, LVM_INSERTCOLUMN, 0, (LPARAM)&COL);

	COL.pszText = (LPWSTR)TEXT("�ܾ�");         // �� ��° ���
	COL.iSubItem = 1;
	SendMessage(g_hListTeamView, LVM_INSERTCOLUMN, 1, (LPARAM)&COL);

	COL.cx = 100;
	COL.pszText = (LPWSTR)TEXT("��������");         // �� ��° ���
	COL.iSubItem = 2;
	SendMessage(g_hListTeamView, LVM_INSERTCOLUMN, 2, (LPARAM)& COL);

	COL.pszText = (LPWSTR)TEXT("���Ƚ��");         // �� ��° ���
	COL.iSubItem = 3;
	SendMessage(g_hListTeamView, LVM_INSERTCOLUMN, 3, (LPARAM)& COL);

	COL.cx = 50;
	COL.pszText = (LPWSTR)TEXT("��ID");         // �ټ� ��° ���
	COL.iSubItem = 4;
	SendMessage(g_hListTeamView, LVM_INSERTCOLUMN, 4, (LPARAM)& COL);

	


}

void ui_TeamListPrint(vector<AccData> *datalist, int size)
{
	ListView_DeleteAllItems(g_hListTeamView);
	//ListView_DeleteItem(hList, idx);

	
	for (int i = 0; i < size; i++)
	{
		AccData info = (*datalist)[i];
		//========================================
		ListTeamPrint(info, i);
		//=========================================
	}

}

void ListTeamPrint(AccData info, int idx)
{
	LVITEM LI;

	// �ؽ�Ʈ�� �̹����� ���� �����۵��� ����Ѵ�.
	LI.mask = LVIF_TEXT;

	LI.iItem = idx;
	LI.iSubItem = 0;
	TCHAR buf[20];
	wsprintf(buf, TEXT("%d"), info.acc_id);
	LI.pszText = buf;         // ù ��° ������
	SendMessage(g_hListTeamView, LVM_INSERTITEM, 0, (LPARAM)&LI);

	LI.iSubItem = 1;
	wsprintf(buf, TEXT("%d"), info.acc_val);
	LI.pszText = buf;
	SendMessage(g_hListTeamView, LVM_SETITEM, 1, (LPARAM)&LI);

	LI.iSubItem = 2;
	LI.pszText = info.acc_date;
	SendMessage(g_hListTeamView, LVM_SETITEM, 2, (LPARAM)&LI);

	LI.iSubItem = 3;
	wsprintf(buf, TEXT("%d"), info.acc_count);
	LI.pszText = buf;
	SendMessage(g_hListTeamView, LVM_SETITEM, 3, (LPARAM)&LI);

	LI.iSubItem = 4;
	wsprintf(buf, TEXT("%d"), info.cus_id);
	LI.pszText = buf;
	SendMessage(g_hListTeamView, LVM_SETITEM, 4, (LPARAM)&LI);


}

void ui_SetComboBox(TCHAR* member)
{
	
	//TCHAR buf[100];
	//wsprintf(buf, TEXT("%d"), member);
	SendMessage(g_combo1, CB_ADDSTRING, 0, (LPARAM)member);
	
}

void ui_ResetComboBox()
{
	SendMessage(g_combo1, CB_RESETCONTENT, 0, 0);
}

/*
void ui_GetHandle(HWND hDlg)
{
	g_hListView = GetDlgItem(hDlg, IDC_LIST1);
}

void ui_SetListViewColumnHeader(HWND hDlg)
{
	LVCOLUMN COL;

	// ����� �߰��Ѵ�.
	COL.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;
	COL.fmt = LVCFMT_LEFT;
	COL.cx = 150;
	COL.pszText = TEXT("�̸�");				// ù ��° ���
	COL.iSubItem = 0;
	SendMessage(g_hListView, LVM_INSERTCOLUMN, 0, (LPARAM)&COL);

	COL.pszText = TEXT("PID");			// �� ��° ���
	COL.iSubItem = 1;
	SendMessage(g_hListView, LVM_INSERTCOLUMN, 1, (LPARAM)&COL);
}



*/