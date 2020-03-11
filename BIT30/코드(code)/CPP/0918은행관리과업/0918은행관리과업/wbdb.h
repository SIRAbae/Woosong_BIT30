//wbdb.h

#include <sql.h>
#include <sqlext.h>

BOOL wbdb_DBConnect();
BOOL wbdb_DBDConnect();

BOOL wbdb_CreateTeamTable();
BOOL wbdb_DropTeamTable();
BOOL wbdb_CreateMemberTable();
BOOL wbdb_DropMemberTable();
BOOL wbdb_CreateSequence();
BOOL wbdb_DropSequence();

BOOL wbdb_InsertTeam(int team_id, TCHAR* team_name);

BOOL wbdb_GetTeamSelectAll(vector<TEAM>* teamlist);

BOOL CommandSql(TCHAR* str);




//
////BOOL mydb_InsertData(Student *pData);
//
//BOOL mydb_SelectData();
//
//BOOL mydb_DeleteData();