//ClassLong.cpp

#include <Windows.h>
#include <tchar.h>


int WINAPI _tWinMain(HINSTANCE hlnst, HINSTANCE hPrev, LPTSTR lpCmdLine, int nShowCmd)
{
	MyRegisterClass(hlnst);
	HWND hwnd = lnitlnstance(hlnst, nShowCmd);
	if (hwnd == 0)
	{
		return FALSE;

	}

	//�ǽð� Ŭ���� ���� ����
	MessageBox(0, TEXT("�ǽð� ���� ����"), TEXT("First"), MB_OK);
	SetClassLongPtr(hwnd, GCLP_HBRBACKGROUND, (LONG)GetStockObject(DKGRAY_BRUSH));
	InvalidateRect(hwnd, NULL, TRUE);
	MessageBox(0, TEXT("Hello, API"), TEXT("First"), MB_OK);

	//�ǽð� Ŭ���� ���� ȹ��
	TCHAR temp{ 126 };
	DWORD flag = GetClassLongPtr(hwnd, GCLP_HBRBACKGROUND);
	wsprintf(temp, _TEXT("R : %d, G : %d, B : %d"), GetRValue(flag), GetGValue(flag), GetRValue(flag));

	MessageBox(0, temp, TEXT("ȹ������"), MB_OK);

	return 0;
}