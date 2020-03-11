//ui.h

void ui_GetTeamCreateInfo(HWND hDlg, TCHAR* ac_id);
void ui_InitTeamListView(HWND hDlg);
void ui_TeamListPrint(vector<ACCOUNT>* aclist, int size);
void ListTeamPrint(ACCOUNT info, int idx);
int ui_getDataid(HWND hDlg);
void ui_getData(HWND hDlg, TCHAR* member_name, TCHAR* member_gender, TCHAR* member_phone, TCHAR* member_date);
int ui_getDataid(HWND hDlg);
int ui_getID(HWND hDlg);
int ui_GetMemberSelectId(HWND hDlg);
int ui_GetMemberSelectInfo(HWND hDlg);
void ui_InitCombo(HWND hDlg);
void ui_GetHandle(HWND hDlg);
void ui_GetSearchName(HWND hDlg, TCHAR* id);

