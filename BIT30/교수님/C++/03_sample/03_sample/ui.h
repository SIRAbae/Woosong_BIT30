//ui.h

void ui_GetTeamCreateInfo(HWND hDlg, int *team_id, TCHAR*team_name);
void ui_InitTeamListView(HWND hDlg);
void ui_TeamListPrint(vector<TEAM> *datalist, int size);
void ListTeamPrint(TEAM info, int idx);

//void ui_GetHandle(HWND hDlg);
//void ui_SetListViewColumnHeader(HWND hDlg);
//void ui_processListPrint(vector<PROINFO> *datalist, int size);
//void ListPrint(PROINFO info, int idx);