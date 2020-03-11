// start.cpp
// 대화상자 기반(page 150)
#include "std.h"

vector<MEMBER> g_memberlist;

BOOL CALLBACK DlgProc(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam) {


	switch (msg)
	{
	case WM_INITDIALOG:
		return OnInitDialog(hDlg, wParam, lParam);

	case WM_COMMAND:
		return OnCommand(hDlg, wParam, lParam);
		/*   switch (LOWORD(wParam)) {
		   case IDCANCEL:
			 EndDialog(hDlg, IDCANCEL);
			 return 0;
		   }
		   return TRUE;*/
	}

	return FALSE;
}


int WINAPI _tWinMain(HINSTANCE hInst, HINSTANCE hPrev, LPTSTR lpCmdLine, int nShowCmd) {
	UINT   ret = DialogBox(hInst,      //instance
		MAKEINTRESOURCE(IDD_DIALOG1),   // 다이얼로그 선택
		0,                        // 부모 윈도우
		DlgProc);                  // Proc..

	return 0;

}