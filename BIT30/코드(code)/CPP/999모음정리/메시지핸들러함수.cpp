//API skeleton.cpp -�޽��� �ڵ鷯 �Լ�
#include <Windows.h>
#include <tchar.h>
#include <vector>
using namespace std;

vector<POINT> g_pointlist;

//========================�޽��� �ڵ鷯 �Լ� ===========================
//�޽��� �߻��� ó�� �Լ� , �Լ��� �̸��� �Ϲ��� ���
//�̸� : OnXXX
LRESULT OnCreate(HWND hwnd, WPARAM wparam, LPARAM)
{
	return 0;
}

LRESULT OnDestroy(HWND hwnd, WPARAM wparam, LPARAM)
{
	PostQuitMessage(0);
	return 0;
}

//page81
LRESULT OnLBUTTONDOWN(HWND hwnd, WPARAM wparam, LPARAM lParam)
{
	
	POINT pt = { LOWORD(lParam),HIWORD(lParam) };

	g_pointlist.push_back(pt);
	InvalidateRect(hwnd, 0, FALSE);
	//================Ÿ��Ʋ�ٿ� ���� ������ ���=======================
	TCHAR temp[20];
	wsprintf(temp, TEXT("���尳�� : %d��"), g_pointlist.size());
	SetWindowText(hwnd, temp);

	return 0;
}
LRESULT OnPaint(HWND hwnd, WPARAM wparam, LPARAM)
{
	PAINTSTRUCT ps;
	HDC hdc = BeginPaint(hwnd, &ps);

	HPEN pen = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
	HPEN old = (HPEN)SelectObject(hdc, pen);

	for (int i = 0; i < (int)g_pointlist.size(); i++)
	{
		POINT pt = g_pointlist[i];
		Rectangle(hdc, pt.x, pt.y, pt.x + 50, pt.y + 50);
	}
	DeleteObject(SelectObject(hdc, old));

	EndPaint(hwnd, &ps);
	return 0;
}

//======================================================================

//proc �⺻ �ڵ�
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_PAINT:			return OnPaint(hwnd, wParam, lParam);
	case WM_LBUTTONDOWN:	return OnLBUTTONDOWN(hwnd, wParam, lParam);
	case WM_CREATE:			return OnCreate(hwnd,wParam,lParam);
	case WM_DESTROY:		return OnDestroy(hwnd, wParam, lParam);
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