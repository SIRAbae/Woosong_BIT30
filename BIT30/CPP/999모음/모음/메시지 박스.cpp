//�޽��� �ڽ�.cpp

#include <Windows.h>

//1) DBCS(char) ����� �ڵ� ANSI����� �ڵ� :Ű���� A
/*
int _stdcall WinMain(HINSTANCE hlnst, HINSTANCE hpev, LPSTR lpCmdLine, int nShowCmd)
{
	return 0;
}
*/

//2) UNICODE(wchar_t) ����� �ڵ�(�����ڵ� ����Ű���� w(Wide)) ������ ũ�� 2BYTE
/*
int _stdcall wWinMain(HINSTANCE hlnst, HINSTANCE hpev, LPWSTR lpCmdLine, int nShowCmd)
{
	return 0;
}
*/

//3) ����Ÿ��(�˾Ƽ� char �� wchar_t�� ó��)
//   ����Ű���� : t 
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