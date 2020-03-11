//PostMessage.cpp

#include <Windows.h>
#include<stdio.h>

#define WM_MYMESSAGE WM_USER + 100


LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{

	case WM_MYMESSAGE:
	{
		TCHAR buf[20];
		wsprintf(buf, TEXT("%d+%d=%d"), wParam, lParam, wParam + lParam);
		MessageBox(hwnd, buf, TEXT(""), MB_OK);
	}
	return wParam + lParam;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, msg, wParam, lParam);
}