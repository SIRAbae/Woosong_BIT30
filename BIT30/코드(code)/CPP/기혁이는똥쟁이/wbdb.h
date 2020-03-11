//wbdb.h

#include <sql.h>
#include <sqlext.h>

BOOL wbdb_DBConnect();
BOOL wbdb_DBDConnect();

BOOL wbdb_InsertTeam(int ac_id, int member_id, TCHAR* ac_money, TCHAR* ac_date, TCHAR* ac_count);
BOOL wbdb_GetTeamSelectAll(vector<ACCOUNT>* aclist);
BOOL CommandSql(TCHAR* str);
BOOL wbdb_DeleteItem(int ac_id);
BOOL wbdb_GetAccountSearch(vector<ACCOUNT>* aclist, TCHAR* name);

//BOOL wbdb_SelectMember(vector<ACCOUNT>* aclist, int sel, int e_id);




//
////BOOL mydb_InsertData(Student *pData);
//
//BOOL mydb_SelectData();
//
//BOOL mydb_DeleteData();