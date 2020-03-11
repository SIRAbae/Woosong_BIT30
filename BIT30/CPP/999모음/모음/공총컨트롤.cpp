//������Ʈ��

#include <Windows.h>
#include <tchar.h>
#include "resource.h"
#include <commctrl.h> 
#pragma comment(lib, "comctl32.lib")   // ������Ʈ�� ���� �ʿ��� h....     


LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	static  HINSTANCE hInst;
	static HWND hProgress;
	static int Pos = 10;
	switch (msg)
	{
	case WM_CREATE:
		// ���� ��Ʈ�� ���� ��Ʈ�� �ʱ�ȭ... 
		InitCommonControls();
		hInst = ((LPCREATESTRUCT)lParam)->hInstance;
		hProgress = CreateWindow(TEXT("msctls_progress32"), TEXT(""),
			WS_CHILD | WS_VISIBLE | WS_BORDER | PBS_SMOOTH,
			10, 10, 300, 20, hwnd, (HMENU)1, hInst, 0);
		// ��Ʈ�� �ʱ�ȭ 
		SendMessage(hProgress, PBM_SETRANGE32, 0, 100);
		SendMessage(hProgress, PBM_SETPOS, 10, 0);
		return 0;


	case WM_LBUTTONDOWN:
		Pos += 10;
		SendMessage(hProgress, PBM_SETPOS, Pos, 0);
		return 0;
	case WM_RBUTTONDOWN:
		Pos -= 10;
		SendMessage(hProgress, PBM_SETPOS, Pos, 0);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, msg, wParam, lParam);
}