//handler.h



BOOL OnInitDialog(HWND hDlg, WPARAM wParam, LPARAM lParam);
BOOL OnCommand(HWND hDlg, WPARAM wParam, LPARAM lParam);


void logmessage(int flag, const char* msg);
void recvmessage(char* msg, int size);
void OnIdCancel(HWND hDlg);
void OnInsert(HWND hDlg);
void OnExit(HWND hDlg);