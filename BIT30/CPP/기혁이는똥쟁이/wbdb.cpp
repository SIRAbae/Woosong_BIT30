//wbdb.cpp

#include "std.h"

#define DBNAME TEXT("wb30db")
#define ID	   TEXT("wb30")
#define PW		TEXT("1234")

SQLHSTMT hStmt;
SQLHENV hEnv;
SQLHDBC hDbc;


BOOL wbdb_DBConnect()
{

	// 연결 설정을 위한 변수들
	SQLRETURN Ret;

	// 1, 환경 핸들을 할당하고 버전 속성을 설정한다.(p1741)
	if (SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv) != SQL_SUCCESS)
		return false;
	if (SQLSetEnvAttr(hEnv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, SQL_IS_INTEGER) != SQL_SUCCESS)
		return false;

	// 2. 연결 핸들을 할당하고 연결한다.
	if (SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc) != SQL_SUCCESS)
		return false;
	// 오라클 서버에 연결하기
	Ret = SQLConnect(hDbc, (SQLTCHAR*)DBNAME, SQL_NTS, (SQLTCHAR*)ID, SQL_NTS, (SQLTCHAR*)PW, SQL_NTS);

	if ((Ret != SQL_SUCCESS) && (Ret != SQL_SUCCESS_WITH_INFO))
		return false;

	// 명령 핸들을 할당한다.
	if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) != SQL_SUCCESS)
		return false;

	return true;
}

BOOL wbdb_DBDConnect()
{
	// 뒷정리
	if (hStmt) SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
	if (hDbc) SQLDisconnect(hDbc);
	if (hDbc) SQLFreeHandle(SQL_HANDLE_DBC, hDbc);
	if (hEnv) SQLFreeHandle(SQL_HANDLE_ENV, hEnv);

	return TRUE;
}


BOOL wbdb_InsertTeam(int ac_id, int member_id, TCHAR* ac_money, TCHAR* ac_date, TCHAR* ac_count)
{
	TCHAR str[1024];
	wsprintf(str, TEXT("insert into account(ac_id,ac_money,ac_date,ac_count) values(ac_register.nextval,'%s',sysdate,'%s');"),
		ac_money, ac_count);
	if (CommandSql(str) == TRUE)
	{
		return CommandSql((TCHAR*)TEXT("commit"));
	}
	return FALSE;
}


BOOL wbdb_DeleteItem(int ac_id)
{
	TCHAR str[1024];
	wsprintf(str, TEXT("delete account where ac_id = %d;"), ac_id);
	if (CommandSql(str) == TRUE)
	{
		TCHAR str[1024] = TEXT("commit");
		return CommandSql(str);
	}
	return FALSE;
}



BOOL CommandSql(TCHAR* str)
{
	if (SQLExecDirect(hStmt, (SQLTCHAR*)str, SQL_NTS) != SQL_SUCCESS)
	{
		return FALSE;
	}
	return TRUE;
}

BOOL wbdb_GetTeamSelectAll(vector<ACCOUNT>* aclist)
{
	int ac_id;
	int member_id;
	SQLTCHAR money[20], date[20], count[20];
	SQLINTEGER  lac_id,lmember_id, lac_money, lac_date, lac_count;

	SQLBindCol(hStmt, 1, SQL_C_ULONG, &ac_id, 0, &lac_id);
	SQLBindCol(hStmt, 2, SQL_C_ULONG, &member_id, 0, &lmember_id);
	SQLBindCol(hStmt, 3, SQL_C_WCHAR, money, sizeof(money), &lac_money);
	SQLBindCol(hStmt, 4, SQL_C_WCHAR, date, sizeof(date), &lac_date);
	SQLBindCol(hStmt, 5, SQL_C_WCHAR, count, sizeof(count), &lac_count);
	



	TCHAR sql[256] = TEXT("select * from account");


	if (SQLExecDirect(hStmt, (SQLTCHAR*)sql, SQL_NTS) != SQL_SUCCESS)
	{
		return FALSE;
	}

	for (int i = 0; SQLFetch(hStmt) != SQL_NO_DATA; i++)
	{
		ACCOUNT data;
		data.ac_id = ac_id;
		data.member_id = member_id;
		_tcscpy(data.ac_money, money);
		_tcscpy(data.ac_count,count );
		_tcscpy(data.ac_date, date);
	

		aclist->push_back(data);

	}
	return true;
}

BOOL wbdb_GetAccountSearch(vector<ACCOUNT>* aclist,TCHAR *name)
{
	int ac_id;
	int member_id;
	SQLTCHAR money[20], date[20], count[20];
	SQLINTEGER  lac_id, lmember_id, lac_money, lac_date, lac_count;

	SQLBindCol(hStmt, 1, SQL_C_ULONG, &ac_id, 0, &lac_id);
	SQLBindCol(hStmt, 2, SQL_C_ULONG, &member_id, 0, &lmember_id);
	SQLBindCol(hStmt, 3, SQL_C_WCHAR, money, sizeof(money), &lac_money);
	SQLBindCol(hStmt, 4, SQL_C_WCHAR, date, sizeof(date), &lac_date);
	SQLBindCol(hStmt, 5, SQL_C_WCHAR, count, sizeof(count), &lac_count);



	TCHAR sql[256];
	wsprintf(sql, TEXT("select * from ACCOUNT where member_id = (select member_ID from member where cus_name = '%s') order by acc_id;"), name);

	if (SQLExecDirect(hStmt, (SQLTCHAR*)sql, SQL_NTS) != SQL_SUCCESS)
	{
		return FALSE;
	}

	for (int i = 0; SQLFetch(hStmt) != SQL_NO_DATA; i++)
	{
		ACCOUNT data;
		data.ac_id = ac_id;
		data.member_id = member_id;
		_tcscpy(data.ac_money, money);
		_tcscpy(data.ac_count, count);
		_tcscpy(data.ac_date, date);


		aclist->push_back(data);

	}
	return true;
}


//
//BOOL wbdb_SelectMember(vector<ACCOUNT>* memberlist, int sel, int e_id, TCHAR* e_name, TCHAR* e_gender, TCHAR* e_phone)
//{
//	int member_id;
//	SQLTCHAR name[50], gender[20], phone[20], date[20];
//	SQLINTEGER lmember_id, lname, lgender, lphone, ldate;
//
//	TCHAR sql[1024];
//
//	if (sel == 0)
//		wsprintf(sql, TEXT("select * from MEMBER where member_id = %d"), e_id);
//	else if (sel == 2)
//		wsprintf(sql, TEXT("select * from MEMBER where member_name = '%s'"), e_name);
//	else if (sel == 1)
//		wsprintf(sql, TEXT("select * from MEMBER where member_gender = '%s'"), e_gender);
//	else if (sel == 3)
//		wsprintf(sql, TEXT("select * from MEMBER where member_phone = '%s'"), e_phone);
//
//	SQLBindCol(hStmt, 2, SQL_C_WCHAR, name, sizeof(name), &lname);
//	SQLBindCol(hStmt, 1, SQL_C_ULONG, &member_id, 0, &lmember_id);
//	SQLBindCol(hStmt, 3, SQL_C_WCHAR, gender, sizeof(gender), &lgender);
//	SQLBindCol(hStmt, 4, SQL_C_WCHAR, phone, sizeof(phone), &lphone);
//	SQLBindCol(hStmt, 5, SQL_C_WCHAR, date, sizeof(date), &ldate);
//
//	if (SQLExecDirect(hStmt, (SQLTCHAR*)sql, SQL_NTS) != SQL_SUCCESS)
//	{
//		return FALSE;
//	}
//
//	for (int i = 0; SQLFetch(hStmt) != SQL_NO_DATA; i++)
//	{
//
//		MEMBER data;
//		data.member_id = member_id;
//		_tcscpy_s(data.member_name, name);
//		_tcscpy_s(data.member_gender, gender);
//		_tcscpy_s(data.member_phone, phone);
//		_tcscpy_s(data.member_date, date);
//
//		memberlist->push_back(data);
//	}
//	return TRUE;
//}