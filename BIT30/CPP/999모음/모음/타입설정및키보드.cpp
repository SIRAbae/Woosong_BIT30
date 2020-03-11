//타입설정및키보드.cpp
#include <Windows.h>
#include <tchar.h>

//1.타입 정의
typedef struct tagSHAPE
{
	int type;		//1:R,2:E
	int penwidth;	//1,3,5
	COLORREF color;	//R,G,B
	int size;		//20,40,60
	POINT pt;		//랜덤

}SHAPE;

//2.핵심 변수 선언
SHAPE g_shape;
POINT g_curpoint;


//3.변수의 초기화

LRESULT OnCreate(HWND hwnd, WPARAM wparam, LPARAM)
{
	g_shape.color = RGB(255, 0, 0);
	g_shape.penwidth = 1;
	g_shape.pt.x = 200;
	g_shape.pt.y = 200;
	g_shape.size = 200;
	g_shape.type = 1;

	g_curpoint.x = 0;
	g_curpoint.y = 0;


	return 0;
}

LRESULT OnDestroy(HWND hwnd, WPARAM wparam, LPARAM)
{
	PostQuitMessage(0);
	return 0;
}

LRESULT OnPaint(HWND hwnd, WPARAM wparam, LPARAM)
{
	PAINTSTRUCT ps;
	HDC hdc = BeginPaint(hwnd, &ps);

	HPEN pen = CreatePen(PS_SOLID, g_shape.penwidth, RGB(0, 0, 0));
	HPEN old = (HPEN)SelectObject(hdc, pen);

	//================도형 출력===================
	HBRUSH brush = CreateSolidBrush(g_shape.color);
	HBRUSH oldb = (HBRUSH)SelectObject(hdc, brush);

	if (g_shape.type == 1)
	{
		Rectangle(hdc, g_shape.pt.x,
			g_shape.pt.y,
			g_shape.pt.x + g_shape.size,
			g_shape.pt.y + g_shape.size);
	}
	else if (g_shape.type == 2)
	{
		Ellipse(hdc, g_shape.pt.x,
			g_shape.pt.y,
			g_shape.pt.x + g_shape.size,
			g_shape.pt.y + g_shape.size);

	}

	DeleteObject(SelectObject(hdc, old));
	DeleteObject(SelectObject(hdc, oldb));
	//=============================================

	//===============좌표 출력=====================
	TCHAR arr[20];
	wsprintf(arr, TEXT("%05d:%05d"),
		g_curpoint.x, g_curpoint.y);
	TextOut(hdc, 0, 0, arr, _tcslen(arr));
	//=============================================
	EndPaint(hwnd, &ps);
	return 0;
}

LRESULT OnLBUTTONDOWN(HWND hwnd, WPARAM wparam, LPARAM lParam)
{

	POINT pt = { LOWORD(lParam),HIWORD(lParam) };

	g_shape.pt = pt;

	InvalidateRect(hwnd, 0, TRUE);

	return 0;
}

LRESULT OnKeyDown(HWND hwnd, WPARAM wparam, LPARAM)
{
	//1.방향키 UP,DOWN을 이용해서 크기 변경
	//2.R(사각형),E(타원) 도형 변경
	switch (wparam)
	{

	case VK_UP:		g_shape.size += 10;				break;
	case VK_DOWN:	g_shape.size -= 10;				break;
	case 'R':		g_shape.type = 1;				break;
	case 'E':		g_shape.type = 2;				break;
	case VK_F1:		g_shape.color = RGB(255, 0, 0);		break;
	case VK_F2:		g_shape.color = RGB(0, 255, 0);		break;
	case VK_F3:		g_shape.color = RGB(0, 0, 255);		break;
	}

	/*
	if (wparam == 'R' && GetKeyState(VK_CONTROL) && 0xFF00)
	{
		MessageBox(0, TEXT("asdasd"), TEXT("asdasd"), MB_OK);
	}
	*/
	InvalidateRect(hwnd, 0, TRUE);
	return 0;
}

LRESULT OnChar(HWND hwnd, WPARAM wparam, LPARAM)
{
	//1.색상 변경 예) ctrl+R
	InvalidateRect(hwnd, 0, TRUE);
	return 0;
}

LRESULT OnMouseMove(HWND hwnd, WPARAM wparam, LPARAM lParam)
{

	POINT pt = { LOWORD(lParam),HIWORD(lParam) };

	g_curpoint = pt;
	RECT rc = { 0,0,200,30 };
	InvalidateRect(hwnd, &rc, TRUE);

	return 0;
}


LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg) {
	case WM_MOUSEMOVE:		return OnMouseMove(hwnd, wParam, lParam);
	case WM_CHAR:			return OnChar(hwnd, wParam, lParam);
	case WM_KEYDOWN:		return OnKeyDown(hwnd, wParam, lParam);
	case WM_PAINT:			return OnPaint(hwnd, wParam, lParam);
	case WM_CREATE:			return OnCreate(hwnd, wParam, lParam);
	case WM_DESTROY:		return OnDestroy(hwnd, wParam, lParam);
	case WM_LBUTTONDOWN:	return OnLBUTTONDOWN(hwnd, wParam, lParam);

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
	wc.lpszMenuName = 0;
	wc.style = 0;

	//2.등록(레지스트리에)
	RegisterClass(&wc);

	//3.윈도우 창 만들기
	HWND hwnd = CreateWindowEx(0,	//WS_EX_TOPMOST
		TEXT("first"),	//클래스 명
		TEXT("Hello"),	//캡션바 내용
		WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0, CW_USEDEFAULT, 0,	//초기 위치
		0, 0,	//부모 윈도우 핸들, 메뉴 핸들
		hInst,	//WinMain의 1번째 파라미터 (exe 주소)
		0);		//생성 인자

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
	return 0;
}