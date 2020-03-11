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
		//��Ʈ�� �ʱ�ȭ
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
			//���޵� �ּҰ��� �̿��Ͽ� �θ𿡰� �ڽ��� ������
			//����.
			GetDlgItemText(hDlg, IDC_EDIT1, pmem->id, sizeof(pmem->id));
			
		
			if (SendMessage(g_hRadio1, BM_GETCHECK, 0, 0) == BST_CHECKED)
				pmem->job = (LPWSTR)TEXT("������");
			if (SendMessage(g_hRadio2, BM_GETCHECK, 0, 0) == BST_CHECKED)
				pmem->job = (LPWSTR)TEXT("������");
			if (SendMessage(g_hRadio3, BM_GETCHECK, 0, 0) == BST_CHECKED)
				pmem->job = (LPWSTR)TEXT("��ó");
			if (SendMessage(g_hRadio4, BM_GETCHECK, 0, 0) == BST_CHECKED)
				pmem->job = (LPWSTR)TEXT("��ؽ�");
			if (SendMessage(g_hRadio5, BM_GETCHECK, 0, 0) == BST_CHECKED)
				pmem->job = (LPWSTR)TEXT("������");

			int idx = SendMessage(g_hCombo1, CB_GETCURSEL, 0, 0);
			pmem->level = idx + 1;

			//����
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