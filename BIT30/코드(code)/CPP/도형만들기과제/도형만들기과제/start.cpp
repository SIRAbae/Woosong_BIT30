#include "std.h"

vector<SHAPE> g_shapelist;
SHAPE g_curshape;
BOOL g_viewcheck;

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_TIMER:
		return OnTimer(hwnd, wParam, lParam);
	case WM_PAINT:
		return OnPaint(hwnd, wParam, lParam);
	case WM_CREATE:
		return OnCreate(hwnd, wParam, lParam);
	case WM_DESTROY:
		return OnDestroy(hwnd, wParam, lParam);
	case WM_CONTEXTMENU:
		return OnContextMenu(hwnd, wParam, lParam);
	case WM_INITMENUPOPUP:
		return OnInitMenuPopup(hwnd, wParam, lParam);
	case WM_LBUTTONDOWN:
		return OnLButtonDown(hwnd, wParam, lParam);
	case WM_COMMAND:
		return OnCommand(hwnd, wParam, lParam);
	case WM_MOUSEMOVE:
		return OnMouseMove(hwnd, wParam, lParam);
	}

	return DefWindowProc(hwnd, msg, wParam, lParam);

}

int WINAPI _tWinMain(HINSTANCE hInst, HINSTANCE hPrev, LPTSTR IpCmdLine,
	int nShowCmd)
{
	//1.������ Ŭ���� �����
	WNDCLASS wc;
	wc.cbWndExtra = 0;
	wc.cbClsExtra = 0;
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.hCursor = LoadCursor(0, IDC_ARROW);
	wc.hIcon = LoadIcon(0, IDI_APPLICATION);
	wc.hInstance = hInst;
	wc.lpfnWndProc = WndProc; //���ν��� ����
	wc.lpszClassName = TEXT("First");
	//wc.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);
	wc.style = 0;

	//2.���(������Ʈ����)
	RegisterClass(&wc);
	//3.������ â �����
	HWND hwnd = CreateWindowEx(0, //WS_EX_TOPMOST
		TEXT("first"), //Ŭ���� ��,
		TEXT("Hello"), //ĸ�ǹ� ����
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0,//�ʱ���ġ
		0, 0,      //�θ� ������ �ڵ�, �޴� �ڵ�
		hInst,      //WinMain�� 1��° �Ķ����(exe �ּ�)
		0 //��������
	);

	//4. ������ �����ֱ�
	ShowWindow(hwnd, SW_SHOW);
	UpdateWindow(hwnd);

	//5. �޽���
	MSG msg;
	while (GetMessage(&msg, 0, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;

}