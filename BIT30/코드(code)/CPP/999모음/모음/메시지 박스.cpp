//메시지 박스.cpp

#include <Windows.h>

//1) DBCS(char) 기반의 코드 ANSI기반의 코드 :키워드 A
/*
int _stdcall WinMain(HINSTANCE hlnst, HINSTANCE hpev, LPSTR lpCmdLine, int nShowCmd)
{
	return 0;
}
*/

//2) UNICODE(wchar_t) 기반의 코드(유니코드 관련키워드 w(Wide)) 문자의 크기 2BYTE
/*
int _stdcall wWinMain(HINSTANCE hlnst, HINSTANCE hpev, LPWSTR lpCmdLine, int nShowCmd)
{
	return 0;
}
*/

//3) 범용타입(알아서 char 나 wchar_t로 처리)
//   관련키워드 : t 
#include <tchar.h>
int WINAPI _tWinMain(HINSTANCE hlnst, HINSTANCE hpev, LPTSTR lpCmdLine, int nShowCmd)
{
	int value = MessageBoxA(0, "Hello,API", "First", MB_YESNO);
	if (value == IDYES)
	{

	}
	else if (value == IDNO)
	{

	}
	MessageBoxW(0, L"Hello,API", L"First", MB_OK | MB_ICONQUESTION);
	MessageBox(0, TEXT("Hello,API"), TEXT("First"), MB_OK);
	return 0;
}