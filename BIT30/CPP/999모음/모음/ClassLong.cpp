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

	//실시간 클래스 정보 수정
	MessageBox(0, TEXT("실시간 정보 수정"), TEXT("First"), MB_OK);
	SetClassLongPtr(hwnd, GCLP_HBRBACKGROUND, (LONG)GetStockObject(DKGRAY_BRUSH));
	InvalidateRect(hwnd, NULL, TRUE);
	MessageBox(0, TEXT("Hello, API"), TEXT("First"), MB_OK);

	//실시간 클래스 정보 획득
	TCHAR temp{ 126 };
	DWORD flag = GetClassLongPtr(hwnd, GCLP_HBRBACKGROUND);
	wsprintf(temp, _TEXT("R : %d, G : %d, B : %d"), GetRValue(flag), GetGValue(flag), GetRValue(flag));

	MessageBox(0, temp, TEXT("획득정보"), MB_OK);

	return 0;
}