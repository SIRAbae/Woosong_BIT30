//wbdb.cpp

#include "std.h"

#define DBNAME TEXT("test")
#define ID	   TEXT("ccm")
#define PW		TEXT("ccm")

SQLHSTMT hStmt;
SQLHENV hEnv;
SQLHDBC hDbc;


BOOL wbdb_DBConnect()
{

	// ���� ������ ���� ������
	SQLRETURN Ret;

	// 1, ȯ�� �ڵ��� �Ҵ��ϰ� ���� �Ӽ��� �����Ѵ�.(p1741)
	if (SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv) != SQL_SUCCESS)
		return false;
	if (SQLSetEnvAttr(hEnv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, SQL_IS_INTEGER) != SQL_SUCCESS)
		return false;

	// 2. ���� �ڵ��� �Ҵ��ϰ� �����Ѵ�.
	if (SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc) != SQL_SUCCESS)
		return false;
	// ����Ŭ ������ �����ϱ�
	Ret = SQLConnect(hDbc, (SQLTCHAR *)DBNAME, SQL_NTS, (SQLTCHAR *)ID, SQL_NTS, (SQLTCHAR *)PW, SQL_NTS);

	if ((Ret != SQL_SUCCESS) && (Ret != SQL_SUCCESS_WITH_INFO))
		return false;

	// ��� �ڵ��� �Ҵ��Ѵ�.
	if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) != SQL_SUCCESS)
		return false;

	return true;
}

BOOL wbdb_DBDConnect()
{
	// ������
	if (hStmt) SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
	if (hDbc) SQLDisconnect(hDbc);
	if (hDbc) SQLFreeHandle(SQL_HANDLE_DBC, hDbc);
	if (hEnv) SQLFreeHandle(SQL_HANDLE_ENV, hEnv);

	return TRUE;
}

BOOL wbdb_CreateTeamTable()
{
	TCHAR str[1024] = TEXT("CREATE TABLE Team (GroupId number,GroupName varchar2(20),CONSTRAINT Group_id_pk primary key(GroupId));");

	return CommandSql(str);
}

BOOL wbdb_DropTeamTable()
{
	TCHAR str[1024] = TEXT("DROP TABLE Team;");

	return CommandSql(str);
}

BOOL wbdb_CreateMemberTable()
{
	TCHAR str[1024] = TEXT("CREATE TABLE member( \
		mem_ID   	 NUMBER,	\
		mem_NAME  	VARCHAR2(20 BYTE) NOT NULL,	\
		mem_gen		VARCHAR2(20 BYTE)			\
			check(mem_gen in('����', '����')),	\
		mem_phone 	 VARCHAR2(20 BYTE),			\
		mem_GID          NUMBER NOT NULL,		\
		mem_date	date,						\
		CONSTRAINT member_PK PRIMARY KEY(mem_ID)); ");

	CommandSql(str);

	TCHAR str1[1024] = TEXT("ALTER TABLE member \
		ADD CONSTRAINT member_FK FOREIGN KEY(mem_ID)	\
		REFERENCES member(mem_ID); ");

	return CommandSql(str1);
}

BOOL wbdb_DropMemberTable()
{
	TCHAR str[1024] = TEXT("DROP TABLE Member;");

	return CommandSql(str);
}

BOOL wbdb_CreateSequence()
{
	TCHAR str[1024] = TEXT("create sequence mem_ID_seq increment by 1 start with 1000; ");

	return CommandSql(str);
}

BOOL wbdb_DropSequence()
{
	TCHAR str[1024] = TEXT("drop sequence mem_ID_seq");

	return CommandSql(str);
}

BOOL wbdb_InsertTeam(int team_id, TCHAR* team_name)
{
	TCHAR str[1024];
	wsprintf(str, TEXT("insert into Team values(%d, '%s');"),
		team_id, team_name);
	if (CommandSql(str) == TRUE)
	{
		return CommandSql(TEXT("commit"));
	}
	return FALSE;
}



BOOL CommandSql(TCHAR *str)
{
	if (SQLExecDirect(hStmt, (SQLTCHAR *)str, SQL_NTS) != SQL_SUCCESS)
	{
		return FALSE;
	}
	return TRUE;
}

BOOL wbdb_GetTeamSelectAll(vector<TEAM>*teamlist)
{
	int team_id;
	SQLTCHAR name[20];
	SQLINTEGER lteam_id, lname;

	SQLBindCol(hStmt, 1, SQL_C_ULONG, &team_id, 0, &lteam_id);
	SQLBindCol(hStmt, 2, SQL_C_CHAR, name, sizeof(name), &lname);

	TCHAR sql[256] = TEXT("select * from team");
	
	if (SQLExecDirect(hStmt, (SQLTCHAR*)sql, SQL_NTS) != SQL_SUCCESS)
	{
		return FALSE;
	}

	for (int i = 0; SQLFetch(hStmt) != SQL_NO_DATA; i++)
	{
		TEAM data;
		data.team_id = team_id;
		_tcscpy(data.team_name, name);
		teamlist->push_back(data);
	}
}


//BOOL mydb_SelectData()
//{
//	SQLCHAR Name[256];
//
//	SQLINTEGER lName, lSnum, lPhone, lEmail;
//	int ssnum;
//
//	SQLCHAR Phone[256];
//	SQLCHAR Email[256];
//
//	SQLBindCol(hStmt, 1, SQL_C_CHAR, Name, sizeof(Name), &lName);
//	SQLBindCol(hStmt, 2, SQL_C_ULONG, &ssnum, 0, &lSnum);
//	SQLBindCol(hStmt, 3, SQL_C_CHAR, Phone, sizeof(Phone), &lPhone);
//	SQLBindCol(hStmt, 4, SQL_C_CHAR, Email, sizeof(Email), &lEmail);
//
//	char sql[256] = "select * from sb";
//
//	if (SQLExecDirect(hStmt, (SQLCHAR*)sql, SQL_NTS) != SQL_SUCCESS)
//	{
//		return FALSE;
//	}
//
//	char name[21], num[21], phoneNumber[21], email[41];
//	int count = 0;
//	for (int i = 0; SQLFetch(hStmt) != SQL_NO_DATA; i++)
//	{
//		wsprintf(name, "%s", Name);
//		wsprintf(num, "%d", ssnum);
//		wsprintf(phoneNumber, "%s", Phone);
//		wsprintf(email, "%s", Email);
//
//		control_GetData(count++, name, num, phoneNumber, email);
//
//	}
//	return TRUE;
//}
//
//BOOL mydb_DeleteData()
//{
//	char sql[256];
//
//	wsprintf(sql, "delete sb");
//	if (SQLExecDirect(hStmt, (SQLCHAR *)sql, SQL_NTS) != SQL_SUCCESS)
//	{
//		return FALSE;
//	}
//	return TRUE;
//}