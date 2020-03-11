#include "std.h"

vector<SHAPE> g_shapelist;
SHAPE g_curshape;
bool g_viewcheck;


// 스켈레톤 코드

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_CREATE:				return OnCreate(hwnd, wParam, lParam);
	case WM_DESTROY:			return OnDestroy(hwnd, wParam, lParam);
	case WM_INITMENUPOPUP:		return OnInitMenuPopup(hwnd, wParam, lParam);
	case WM_COMMAND:			return OnCommand(hwnd, wParam, lParam);
	case WM_CONTEXTMENU:		return OnContextMenu(hwnd, wParam, lParam);
	case WM_LBUTTONDOWN:		return OnLButtonDown(hwnd, wParam, lParam);
	case WM_PAINT:				return OnPaint(hwnd, wParam, lParam);
	case WM_MOUSEMOVE:			return OnMouseMove(hwnd, wParam, lParam);
	case WM_TIMER:				return OnTimer(hwnd, wParam, lParam);

	}
	return DefWindowProc(hwnd, msg, wParam, lParam);
}

int WINAPI _tWinMain(HINSTANCE hInst, HINSTANCE hPrev, LPTSTR IpCmdLine, int nShowCmd)
{
	//1.윈도우 클래스 만들기
	WNDCLASS wc;
	wc.cbWndExtra = 0;
	wc.cbClsExtra = 0;
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.hCursor = LoadCursor(0, IDC_ARROW);
	wc.hIcon = LoadIcon(0, IDI_APPLICATION);
	wc.hInstance = hInst;
	wc.lpfnWndProc = WndProc;
	wc.lpszClassName = TEXT("First");
	wc.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);
	wc.style = 0;

	//2. 등록 (레지스트리)
	RegisterClass(&wc);

	//3.윈도우 창 만들기
	HWND hwnd = CreateWindowEx(0, TEXT("first"), TEXT("즐거운 도형 만들기"), WS_OVERLAPPEDWINDOW &~WS_MINIMIZEBOX, CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, 0, 0, hInst, 0);

	//4.윈도우 보여주기
	ShowWindow(hwnd, SW_SHOW);
	UpdateWindow(hwnd);

	//5. 메세지
	MSG msg;
	while (GetMessage(&msg, 0, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

