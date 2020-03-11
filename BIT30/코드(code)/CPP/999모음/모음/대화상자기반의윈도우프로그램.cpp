
#include <Windows.h>
#include <tchar.h>
#include "resource1.h"


BOOL CALLBACK DlgProc(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg)
	{
	case WM_INITDIALOG: { }
						return TRUE;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDCANCEL: EndDialog(hDlg, IDCANCEL); return 0;
		}
		return TRUE;
	}
	return FALSE;
}
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE, PSTR lpCmdLine, int nShowCmd) {

	UINT ret = DialogBox(hInst,// instance 
		MAKEINTRESOURCE(IDD_DIALOG1), // ���̾�α� ���� 
		0,   // �θ� ������ 
		DlgProc);   // Proc.. 
	return 0;
}