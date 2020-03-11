//handler.cpp

#include "std.h"


BOOL  OnInitDialog(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	ui_InitTeamListView(hDlg);

	return TRUE;
}

BOOL  OnCommand(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	switch (LOWORD(wParam))
	{
		//DB접속
	case IDC_BUTTON1:   OnDBConnect(hDlg);      return 0;
		//DB접속해제
	case IDC_BUTTON2:	OnDBDConnect(hDlg);		return 0;
	case IDC_BUTTON7:	OnPrintAll(hDlg);		return 0;
		//DDL문===================================================
		//Tean 테이블 생성
	//case IDC_BUTTON3:	OnCreateTeamTable(hDlg);	break;
	//	//Tean 테이블 삭제
	//case IDC_BUTTON4:	OnDropTeamTable(hDlg);		break;
	//	//Member 테이블 생성
	//case IDC_BUTTON5:	OnCreateMemberTable(hDlg);	break;
	//	//Member 테이블 삭제
	//case IDC_BUTTON6:	OnDropMemberTable(hDlg);	break;
	//	//시퀀스 생성
	//case IDC_BUTTON7:	OnCreateSequence(hDlg);		break;
	//	//시퀀스 삭제
	//case IDC_BUTTON8:	OnDropSequence(hDlg);		break;
	//	//========================================================
	//	//Team등록
	case IDC_BUTTON4:	OnInsertTeam(hDlg);			return 0;
	case IDC_BUTTON5:	OnDeleteMember(hDlg);		return 0;
	case IDC_BUTTON3:	OnSearchAccount(hDlg);		return 0;
	case IDCANCEL:		OnCancel(hDlg);				return 0;
	}
	return TRUE;		
}



//==========================================================
//connect, DCONNECT
//==========================================================

void OnDBConnect(HWND hDlg)
{
	if (wbdb_DBConnect() == TRUE)
	{
		vector<AccName> g_members;
		MessageBox(NULL, TEXT("DB접속 성공"), TEXT("알림"), MB_OK);
		
		wbdb_GetMemberName(&g_members);
		ui_ResetComboBox();
		for (int i = 0; i < (int)g_members.size(); i++)
		{
			ui_SetComboBox(g_members[i].cus_name);
		}
		
	}
	else
		MessageBox(NULL, TEXT("DB접속 실패"), TEXT("알림"), MB_OK);

	/*TCHAR sql[256] = TEXT("select * from customer_mgr");
	CommandSql(sql);*/
	
	//MessageBox(NULL, sql, TEXT("알림"), MB_OK);
}

void OnDBDConnect(HWND hDlg)
{
	if (wbdb_DBDConnect() == TRUE)
	{
		ui_ResetComboBox();
		MessageBox(NULL, TEXT("DB접속해제 성공"), TEXT("알림"), MB_OK);
	}
	else
		MessageBox(NULL, TEXT("DB접속해제 실패"), TEXT("알림"), MB_OK);
}

//-----------------------------------------------------------





//==========================================================
//DDL
//==========================================================
void OnCreateTeamTable(HWND hDlg)
{
	if (wbdb_CreateTeamTable() == TRUE)
		MessageBox(NULL, TEXT("성공"), TEXT("알림"), MB_OK);
	else
		MessageBox(NULL, TEXT("실패"), TEXT("알림"), MB_OK);
}

void OnDropTeamTable(HWND hDlg)
{
	if (wbdb_DropTeamTable() == TRUE)
		MessageBox(NULL, TEXT("성공"), TEXT("알림"), MB_OK);
	else
		MessageBox(NULL, TEXT("실패"), TEXT("알림"), MB_OK);
}

void OnCreateMemberTable(HWND hDlg)
{
	if (wbdb_CreateMemberTable() == TRUE)
		MessageBox(NULL, TEXT("성공"), TEXT("알림"), MB_OK);
	else
		MessageBox(NULL, TEXT("실패"), TEXT("알림"), MB_OK);
}

void OnDropMemberTable(HWND hDlg)
{
	if (wbdb_DropMemberTable() == TRUE)
		MessageBox(NULL, TEXT("성공"), TEXT("알림"), MB_OK);
	else
		MessageBox(NULL, TEXT("실패"), TEXT("알림"), MB_OK);
}

void OnCreateSequence(HWND hDlg)
{
	if (wbdb_CreateSequence() == TRUE)
		MessageBox(NULL, TEXT("성공"), TEXT("알림"), MB_OK);
	else
		MessageBox(NULL, TEXT("실패"), TEXT("알림"), MB_OK);
}

void OnDropSequence(HWND hDlg)
{
	if (wbdb_DropSequence() == TRUE)
		MessageBox(NULL, TEXT("성공"), TEXT("알림"), MB_OK);
	else
		MessageBox(NULL, TEXT("실패"), TEXT("알림"), MB_OK);
}
//-----------------------------------------------------------






//==========================================================
//DML
//==========================================================

void OnInsertTeam(HWND hDlg)
{
	TCHAR id[30];
	
	ui_GetTeamCreateInfo(hDlg, id);
	if (wbdb_InsertTeam(id) == TRUE)
	{
		OnPrintAll(hDlg);
		/*vector<TEAM> teamlist;
		wbdb_GetTeamSelectAll(&teamlist);
		ui_TeamListPrint(&teamlist, teamlist.size());*/
	}
	else
		MessageBox(NULL, TEXT("실패"), TEXT("알림"), MB_OK);
}

void OnUpdateMember(HWND hDlg)
{
	int id = 0;
	TCHAR name[20];
	TCHAR phone[125];
	TCHAR date[125];
	TCHAR gender[20];

	ui_GetAllInfo(hDlg, &id, name, phone, date, gender);
	if (wbdb_UpdateTeam(id, name, phone, date, gender) == TRUE)
	{
		OnPrintAll(hDlg);
		/*vector<TEAM> teamlist;
		wbdb_GetTeamSelectAll(&teamlist);
		ui_TeamListPrint(&teamlist, teamlist.size());*/
	}
	else
		MessageBox(NULL, TEXT("실패"), TEXT("알림"), MB_OK);
}

void OnDeleteMember(HWND hDlg)
{
	int id = 0;
	ui_GetIDInfo(hDlg, &id);
	if (wbdb_DeleteTeam(id) == TRUE)
	{
		OnPrintAll(hDlg);
		/*vector<TEAM> teamlist;
		wbdb_GetTeamSelectAll(&teamlist);
		ui_TeamListPrint(&teamlist, teamlist.size());*/
	}
	else
		MessageBox(NULL, TEXT("실패"), TEXT("알림"), MB_OK);
}

void OnPrintAll(HWND hDlg)
{
	vector<AccData> teamlist;
	wbdb_GetTeamSelectAll(&teamlist);
	ui_TeamListPrint(&teamlist,teamlist.size());
	
}

void OnSearchAccount(HWND hDlg)
{
	vector<AccData> teamlist;

	TCHAR name[20];
	ui_GetSearchName(hDlg, name);

	wbdb_GetSearchSelectAll(&teamlist, name);
	ui_TeamListPrint(&teamlist, teamlist.size());
}


//-----------------------------------------------------------




void OnCancel(HWND hDlg)
{
	EndDialog(hDlg, IDCANCEL);

}


//void OnPrint(HWND hDlg)
//{
//	GetProcessList(hDlg);
//}
//
//void GetProcessList(HWND hDlg)
//{
//	//프로세스 리스트 출력
//	vector<PROINFO> datalist;
//	int size;
//	pro_getProcessList(&datalist, &size);
//	coll_proListSave(&datalist, size);
//	ui_processListPrint(&datalist, size);
//}
