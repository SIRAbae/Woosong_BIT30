//ui.h

void ui_GetControlHandle(HWND hDlg);
void ui_InitListView(HWND hDlg);
void ui_SetAddress(HWND hDlg, TCHAR* ip, int port);

void ui_GetAddress(HWND hDlg, TCHAR* ip, int *port);
void ui_GetInsertData(HWND hDlg, TCHAR* id, TCHAR* pw, TCHAR* name, TCHAR* phone, int *age);
void ui_GetName(HWND hDlg, TCHAR* name); //Select, Delete
void ui_GetUpdate(HWND hDlg, TCHAR*name, TCHAR* phone, int* age);