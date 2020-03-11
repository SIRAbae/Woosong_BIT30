//InsertProc.cpp

#include "std.h"

BOOL CALLBACK InsertProc(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
	static MEMBER* pmem;
	static HWND g_hRadio1;
	static HWND g_hRadio2;
	static HWND g_hRadio3;
	static HWND g_hRadio4;//IDC_RADIO1
	static HWND g_hRadio5;
	static HWND g_hCombo1;		//IDC_COMBO1

	switch (msg)
	{
	case WM_INITDIALOG:
		pmem = (MEMBER*)lParam;
		//컨트롤 초기화
		g_hRadio1 = GetDlgItem(hDlg, IDC_RADIO1);
		g_hRadio2 = GetDlgItem(hDlg, IDC_RADIO2);
		g_hRadio3 = GetDlgItem(hDlg, IDC_RADIO3);
		g_hRadio4 = GetDlgItem(hDlg, IDC_RADIO4);
		g_hRadio5 = GetDlgItem(hDlg, IDC_RADIO5);
		g_hCombo1 = GetDlgItem(hDlg, IDC_COMBO1);
		for (int i = 1; i <= 100; i++)
		{
			TCHAR temp[10];
			wsprintf(temp, TEXT("%d"), i);
			SendMessage(g_hCombo1, CB_ADDSTRING, 0, (LPARAM)temp);
		}

		return TRUE;

	case WM_COMMAND:		//page146
		switch (LOWORD(wParam))
		{
		case IDOK:
		{
			//전달된 주소값을 이용하여 부모에게 자신의 정보를
			//전달.
			GetDlgItemText(hDlg, IDC_EDIT1, pmem->id, sizeof(pmem->id));
			
		
			if (SendMessage(g_hRadio1, BM_GETCHECK, 0, 0) == BST_CHECKED)
				pmem->job = (LPWSTR)TEXT("워리어");
			if (SendMessage(g_hRadio2, BM_GETCHECK, 0, 0) == BST_CHECKED)
				pmem->job = (LPWSTR)TEXT("메이지");
			if (SendMessage(g_hRadio3, BM_GETCHECK, 0, 0) == BST_CHECKED)
				pmem->job = (LPWSTR)TEXT("아처");
			if (SendMessage(g_hRadio4, BM_GETCHECK, 0, 0) == BST_CHECKED)
				pmem->job = (LPWSTR)TEXT("어쌔신");
			if (SendMessage(g_hRadio5, BM_GETCHECK, 0, 0) == BST_CHECKED)
				pmem->job = (LPWSTR)TEXT("성직자");

			int idx = SendMessage(g_hCombo1, CB_GETCURSEL, 0, 0);
			pmem->level = idx + 1;

			//종료
			EndDialog(hDlg, IDOK);
		}
		return TRUE;

		case IDCANCEL: EndDialog(hDlg, IDCANCEL);
			return 0;
		}
		return TRUE;
	}
	return FALSE;
}