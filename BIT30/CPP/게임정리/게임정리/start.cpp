//start.cpp
#include "std.h"

//extern vector<MEMBER> g_memberlist;

BOOL CALLBACK DlgProc(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_INITDIALOG:		return OnInitDialog(hDlg, wParam, lParam);
	case WM_COMMAND:		return OnCommand(hDlg, wParam, lParam);
	}
	return FALSE;
}

int WINAPI _tWinMain(HINSTANCE hInst, HINSTANCE, LPTSTR lpCmdLine, int nShowCmd)
{

	//freopen("CONOUT$",   // console ��
	//	"wt",        // text write ����
	//	stdout);	  // stdout �� ����..


	UINT ret = DialogBox(hInst,
		MAKEINTRESOURCE(IDD_DIALOG2),
		0, DlgProc);

	return 0;
}

