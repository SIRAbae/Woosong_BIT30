//wbdb.h


BOOL wbdb_DBConnect();
BOOL wbdb_DBDConnect();

BOOL wbdb_CreateTeamTable();
BOOL wbdb_DropTeamTable();
BOOL wbdb_CreateMemberTable();
BOOL wbdb_DropMemberTable();
BOOL wbdb_CreateSequence();
BOOL wbdb_DropSequence();

BOOL wbdb_InsertTeam(TCHAR*id);
BOOL wbdb_UpdateTeam(int id, TCHAR* name, TCHAR*phone, TCHAR*date, TCHAR* gender);
BOOL wbdb_DeleteTeam(int id);

BOOL wbdb_GetTeamSelectAll(vector<AccData>*teamlist);
BOOL wbdb_GetMemberName(vector<AccName>* memberlist);
BOOL wbdb_GetSearchSelectAll(vector<AccData>*teamlist, TCHAR* name);

BOOL CommandSql(TCHAR *str);




//
////BOOL mydb_InsertData(Student *pData);
//
//BOOL mydb_SelectData();
//
//BOOL mydb_DeleteData();