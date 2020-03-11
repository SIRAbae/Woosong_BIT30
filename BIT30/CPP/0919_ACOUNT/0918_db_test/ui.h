//ui.h
void ui_GetTeamCreateInfo(HWND hDlg, TCHAR*id);
void ui_GetSearchName(HWND hDlg, TCHAR*id);
void ui_GetAllInfo(HWND hDlg, int *id, TCHAR*name, TCHAR*phone, TCHAR*date, TCHAR*gender);
void ui_GetIDInfo(HWND hDlg, int *id);
void ui_InitTeamListView(HWND hDlg);
void ui_TeamListPrint(vector<AccData> *datalist, int size);
void ListTeamPrint(AccData info, int idx);
void ui_SetComboBox(TCHAR* member);
void ui_ResetComboBox();
//void ui_GetHandle(HWND hDlg);
//void ui_SetListViewColumnHeader(HWND hDlg);
//void ui_processListPrint(vector<PROINFO> *datalist, int size);
//void ListPrint(PROINFO info, int idx);