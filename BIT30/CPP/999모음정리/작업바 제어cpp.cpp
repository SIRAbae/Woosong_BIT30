#include <Windows.h>
#include <tchar.h>

int WINAPI _tWinMain(HINSTANCE hlnst, HINSTANCE hpev, LPTSTR lpCmdLine, int nShowCmd)
{
	HWND hwnd = FindWindow(TEXT("Shell_TrayWnd"), 0);
	ShowWindow(hwnd, SW_SHOW);
}