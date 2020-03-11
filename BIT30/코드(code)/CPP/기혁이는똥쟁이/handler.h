//handler.h

BOOL  OnInitDialog(HWND hDlg, WPARAM wParam, LPARAM lParam);
BOOL  OnCommand(HWND hDlg, WPARAM wParam, LPARAM lParam);

void OnDBConnect(HWND hDlg);
void OnDBDConnect(HWND hDlg);
void OnInsert(HWND hDlg);
void OnPrint(HWND hDlg);
//void OnTeaminsert(HWND hDlg);
void OnInsertTeam(HWND hDlg);
void OnCancel(HWND hDlg);
void OnDelete(HWND hDlg);
void OnSelectAccount(HWND hDlg);