// ����Ŭ������ ����

#include <Windows.h>
#include <tchar.h>


WNDPROC old; // ������ EditBox�� �޼��� ó���Լ��� �ּҸ� ���� ���� 
LRESULT CALLBACK foo(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_CHAR:
		if ((wParam >= '0' && wParam <= '9') || wParam == 8)
			
			return CallWindowProc(old, hwnd, msg, wParam, lParam);
		return 0; // ���� �̿��� ���� �����Ѵ�. 
	}
	// ������ ��� �޼����� ������ �Լ��� �����Ѵ�. 
	return CallWindowProc(old, hwnd, msg, wParam, lParam);
}
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	static HWND hEdit;
	
	
	
	switch (msg)
	{
	case WM_CREATE:
		hEdit = CreateWindow(TEXT("edit"), TEXT(""), WS_CHILD | WS_VISIBLE | WS_BORDER, 10, 10, 200, 200, hwnd, (HMENU)1, 0, 0);
		old = (WNDPROC)SetWindowLong(hEdit, GWL_WNDPROC, (LONG)foo);
		SetFocus(hEdit);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, msg, wParam, lParam);
}