//GetTextMatrix.cpp
#include <Windows.h>
#include <tchar.h>
//proc �⺻ �ڵ�
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	static int cxChar, cyChar;

	switch (msg)
	{
	case WM_CREATE:
	{
		TEXTMETRIC tm;
		HDC hdc;
		hdc = GetDC(hwnd);
		GetTextMetrics(hdc, &tm);
		cxChar = tm.tmAveCharWidth;
		cyChar = tm.tmHeight + tm.tmExternalLeading;
		ReleaseDC(hwnd, hdc);

	}
	return 0;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwnd, &ps);
		TCHAR buf[20];
		wsprintf(buf, TEXT("%d,%d"), cxChar, cyChar);
		TextOut(hdc, 10, 10, buf, wcslen(buf));
		EndPaint(hwnd, &ps);
	}
	return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;

	}
	return DefWindowProc(hwnd, msg, wParam, lParam);

}

int WINAPI _tWinMain(HINSTANCE hInst, HINSTANCE hPrev, LPTSTR IpCmdLine, int nShowCmd)
{
	//1.������ Ŭ���� �����
	WNDCLASS wc;
	wc.cbWndExtra = 0;
	wc.cbClsExtra = 0;
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.hCursor = LoadCursor(0, IDC_ARROW);
	wc.hIcon = LoadIcon(0, IDI_APPLICATION);
	wc.hInstance = hInst;
	wc.lpfnWndProc = WndProc;
	wc.lpszClassName = TEXT("First");
	wc.lpszMenuName = 0;
	wc.style = 0;

	//2.���(������Ʈ����)
	RegisterClass(&wc);

	//3.������ â �����
	HWND hwnd = CreateWindowEx(0,	//WS_EX_TOPMOST
		TEXT("first"),	//Ŭ���� ��
		TEXT("Hello"),	//ĸ�ǹ� ����
		WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0, CW_USEDEFAULT, 0,	//�ʱ� ��ġ
		0, 0,	//�θ� ������ �ڵ�, �޴� �ڵ�
		hInst,	//WinMain�� 1��° �Ķ���� (exe �ּ�)
		0);		//���� ����

	//4.������ �����ֱ�
	ShowWindow(hwnd, SW_SHOW);
	UpdateWindow(hwnd);

	//5. �޼���
	MSG msg;
	while (GetMessage(&msg, 0, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}