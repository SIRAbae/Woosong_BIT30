//API skeleton.cpp -메시지 핸들러 함수
#include <Windows.h>
#include <tchar.h>
#include <vector>
using namespace std;

vector<POINT> g_pointlist;

//========================메시지 핸들러 함수 ===========================
//메시지 발생시 처리 함수 , 함수의 이름이 암묵적 약속
//이름 : OnXXX
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
	//================타이틀바에 저장 개수를 출력=======================
	TCHAR temp[20];
	wsprintf(temp, TEXT("저장개수 : %d개"), g_pointlist.size());
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

//proc 기본 코드
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