#include <Windows.h>
#include <tchar.h>

int WINAPI _tWinMain(HINSTANCE hlnst, HINSTANCE hpev, LPTSTR lpCmdLine, int nShowCmd) {

	HWND hwnd = FindWindow(TEXT("Shell_TrayWnd"), 0);
	if (IsWindowVisible(hwnd))
		ShowWindow(hwnd, SW_HIDE);
	else
		ShowWindow(hwnd, SW_SHOW);
	return 

}