//wbdb.cpp

#include "std.h"

#define DBNAME TEXT("member1")
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
	Ret = SQLConnect(hDbc, (SQLTCHAR *)DBNAME, SQL_NTS, (SQLTCHAR *)ID, SQL_NTS, (SQLTCHAR *)PW, SQL_NTS);

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
			check(mem_gen in('남성', '여성')),	\
		mem_phone 	 VARCHAR2(20 BYTE),			\
		mem_GID          NUMBER NOT NULL,		\
		mem_date	date,						\
		CONSTRAINT member_PK PRIMARY KEY(mem_ID)); ");


	TCHAR str1[1024] = TEXT("ALTER TABLE member \
		ADD CONSTRAINT member_FK FOREIGN KEY(mem_ID)	\
		REFERENCES member(mem_ID); ");

	return CommandSql(str1);
	CommandSql(str);
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

BOOL wbdb_InsertTeam(TCHAR*id)
{
	TCHAR str[1024];
	//wsprintf(str, TEXT("insert into customer_mgr values(%d, '%s',1321,'12/13/12','F');"),
		//team_id, team_name);
	wsprintf(str, TEXT("insert into account_table(acc_id, cus_id, acc_date) VALUES(acc_id_num.nextval,(select CUS_ID from CUSTOMER_MGR WHERE cus_name = '%s'),sysdate); "),id);
	if (CommandSql(str) == TRUE)
	{
		TCHAR str[1024] = TEXT("commit");
		return CommandSql(str);
	}
	return FALSE;
}

BOOL wbdb_UpdateTeam(int id, TCHAR* name, TCHAR*phone, TCHAR*date, TCHAR* gender)
{
	TCHAR str[1024];
	//wsprintf(str, TEXT("insert into customer_mgr values(%d, '%s',1321,'12/13/12','F');"),
		//team_id, team_name);
	
	wsprintf(str, TEXT("UPDATE CUSTOMER_MGR SET cus_name = '%s', cus_phone = '%s', cus_date = '%s', cus_gender = '%s' WHERE cus_id = %d; "), name, phone,date, gender,id);
	if (CommandSql(str) == TRUE)
	{
		TCHAR str[1024] = TEXT("commit");
		return CommandSql(str);
	}
	return FALSE;
}

BOOL wbdb_DeleteTeam(int id)
{
	TCHAR str[1024];
	
	wsprintf(str, TEXT("DELETE ACCOUNT_TABLE where acc_id = %d; "), id);
	if (CommandSql(str) == TRUE)
	{
		TCHAR str[1024] = TEXT("commit");
		return CommandSql(str);
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

BOOL wbdb_GetTeamSelectAll(vector<AccData>*teamlist)
{
	int acc_id, acc_val, acc_count, cus_id;
	SQLINTEGER lacc_id,lacc_val,lacc_count,lcus_id;
	
	SQLTCHAR date[50];
	SQLINTEGER ldate;
	
	SQLBindCol(hStmt, 1, SQL_C_ULONG, &acc_id, 0, &lacc_id);
	SQLBindCol(hStmt, 2, SQL_C_ULONG, &acc_val, 0, &lacc_val);
	SQLBindCol(hStmt, 3, SQL_C_WCHAR, date, sizeof(date), &ldate);
	SQLBindCol(hStmt, 4, SQL_C_ULONG, &acc_count, 0, &lacc_count);
	SQLBindCol(hStmt, 5, SQL_C_ULONG, &cus_id, 0, &lcus_id);

	TCHAR sql[256] = TEXT("select * from ACCOUNT_TABLE order by acc_id;");

	if (SQLExecDirect(hStmt, (SQLTCHAR*)sql, SQL_NTS) != SQL_SUCCESS)
	{
		return FALSE;
	}

	for (int i = 0; SQLFetch(hStmt) != SQL_NO_DATA; i++)
	{
		AccData data;

		data.acc_id = acc_id;
		data.acc_val = acc_val;
		data.acc_count = acc_count;
		data.cus_id = cus_id;
		_tcscpy_s(data.acc_date, date);

		teamlist->push_back(data);
	}
	return true;
}

BOOL wbdb_GetMemberName(vector<AccName>* memberlist)
{
	//int id;
	//SQLINTEGER lteam_id;

	SQLTCHAR name[50];
	SQLINTEGER lname;

	//SQLBindCol(hStmt, 1, SQL_C_ULONG, &id, 0, &lteam_id);
	SQLBindCol(hStmt, 1, SQL_C_WCHAR, name, sizeof(name), &lname);

	TCHAR sql[256] = TEXT("select cus_name from customer_mgr;");

	if (SQLExecDirect(hStmt, (SQLTCHAR*)sql, SQL_NTS) != SQL_SUCCESS)
	{
		return FALSE;
	}

	for (int i = 0; SQLFetch(hStmt) != SQL_NO_DATA; i++)
	{
		AccName data = {0};
		_tcscpy_s(data.cus_name, name);
		memberlist->push_back(data);
	}
	return TRUE;
}

BOOL wbdb_GetSearchSelectAll(vector<AccData>*teamlist, TCHAR* name)
{
	int acc_id, acc_val, acc_count, cus_id;
	SQLINTEGER lacc_id, lacc_val, lacc_count, lcus_id;

	SQLTCHAR date[50];
	SQLINTEGER ldate;

	SQLBindCol(hStmt, 1, SQL_C_ULONG, &acc_id, 0, &lacc_id);
	SQLBindCol(hStmt, 2, SQL_C_ULONG, &acc_val, 0, &lacc_val);
	SQLBindCol(hStmt, 3, SQL_C_WCHAR, date, sizeof(date), &ldate);
	SQLBindCol(hStmt, 4, SQL_C_ULONG, &acc_count, 0, &lacc_count);
	SQLBindCol(hStmt, 5, SQL_C_ULONG, &cus_id, 0, &lcus_id);

	TCHAR sql[256]; 
	wsprintf(sql,TEXT("select * from ACCOUNT_TABLE where cus_id = (select CUS_ID from CUSTOMER_MGR where cus_name = '%s') order by acc_id;"), name);

	if (SQLExecDirect(hStmt, (SQLTCHAR*)sql, SQL_NTS) != SQL_SUCCESS)
	{
		return FALSE;
	}

	for (int i = 0; SQLFetch(hStmt) != SQL_NO_DATA; i++)
	{
		AccData data;

		data.acc_id = acc_id;
		data.acc_val = acc_val;
		data.acc_count = acc_count;
		data.cus_id = cus_id;
		_tcscpy_s(data.acc_date, date);

		teamlist->push_back(data);
	}
	return true;
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