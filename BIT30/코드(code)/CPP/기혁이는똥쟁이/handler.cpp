//handler.cpp

#include "std.h"
vector<ACCOUNT> aclist;

BOOL  OnInitDialog(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	ui_GetHandle(hDlg);
	ui_InitCombo(hDlg);
	ui_InitTeamListView(hDlg);

	return TRUE;
}

BOOL  OnCommand(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	switch (LOWORD(wParam))
	{
		//DB����
	case IDC_BUTTON1:   OnDBConnect(hDlg);      return 0;
		//DB��������
	case IDC_BUTTON2:	OnDBDConnect(hDlg);		return 0;
		//���� ID ����
	case IDC_BUTTON3:	OnInsert(hDlg);			return 0;
		//���� ID ����
	case IDC_BUTTON4:	OnDelete(hDlg);		return 0;
		//�� ID �˻�
	//case IDC_BUTTON5:	OnSelectMember(hDlg);		return 0;
		//���� ID �˻�
	case IDC_BUTTON6:	OnSelectAccount(hDlg);		return 0;
		//��ü���
	case IDC_BUTTON7:	OnPrint(hDlg);		return 0;
	case IDCANCEL:		OnCancel(hDlg);			return 0;
	}
	return TRUE;
}

void OnDBConnect(HWND hDlg)
{
	if (wbdb_DBConnect() == TRUE)
		MessageBox(NULL, TEXT("DB���� ����"), TEXT("�˸�"), MB_OK);
	else
		MessageBox(NULL, TEXT("DB���� ����"), TEXT("�˸�"), MB_OK);
}

void OnDBDConnect(HWND hDlg)
{
	if (wbdb_DBDConnect() == TRUE)
		MessageBox(NULL, TEXT("DB�������� ����"), TEXT("�˸�"), MB_OK);
	else
		MessageBox(NULL, TEXT("DB�������� ����"), TEXT("�˸�"), MB_OK);
}

////DDL=========================================================

void OnInsert(HWND hDlg)
{
	OnInsertTeam(hDlg);

	MessageBox(hDlg, TEXT("�ű԰� ����"), TEXT("�˸�"), 0);
}

void OnDelete(HWND hDlg)
{
	int ID = ui_getID(hDlg);
	if (wbdb_DeleteItem(ID) == TRUE)
	{
		wbdb_DeleteItem(ID);
		/*	ui_setEditClear(hDlg);*/
		MessageBox(hDlg, TEXT("���� ����"), TEXT("�˸�"), 0);
	}
	else
		MessageBox(hDlg, TEXT("���� ����"), TEXT("�˸�"), 0);
}


void OnInsertTeam(HWND hDlg)
{
	int  ac_id =0;
	int member_id=0;
	TCHAR ac_money[20];
	TCHAR ac_date[20];
	TCHAR ac_count[20];


	//ui_GetTeamCreateInfo(hDlg, &ac_id,&member_id, ac_money, ac_date, ac_count);
	wbdb_InsertTeam(ac_id, member_id, ac_money, ac_date, ac_count);
	
}


void OnPrint(HWND hDlg)
{
	vector<ACCOUNT> aclist;
	wbdb_GetTeamSelectAll(&aclist);
	ui_TeamListPrint(&aclist, aclist.size());
}




void OnCancel(HWND hDlg)
{
	EndDialog(hDlg, IDCANCEL);

}

void OnSelectAccount(HWND hDlg)
{
	vector<ACCOUNT> aclist;
	
	TCHAR name[20];
	ui_GetSearchName(hDlg, name);
	wbdb_GetAccountSearch(&aclist,name);
	ui_TeamListPrint(&aclist, aclist.size());
}

