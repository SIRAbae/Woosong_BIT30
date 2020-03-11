//큐,비큐.cpp
#include <Windows.h>
#include <tchar.h>
//proc 기본 코드

//사용자 정의 메세지
#define WM_MYMESSAGE WM_USER + 100
#define WM_MYMESSAGE1 WM_USER + 200

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_MYMESSAGE:
		SetWindowText(hwnd, TEXT("첫번째 메세지"));
		return 0;

	case WM_MYMESSAGE1:
		SetWindowText(hwnd, TEXT("두번째 메세지"));
		return 0;

	case WM_LBUTTONDOWN:
		//비큐 메세지  Send(함수에서 함수 프로시저가 호출된 상태에서 다시 프로시저 호출)
		SendMessage(hwnd, WM_MYMESSAGE, 0, 0);
		return 0;

	case WM_RBUTTONDOWN:
		//큐 메세지	Post(프로시저가 종료된 후에도 프로시저에 저장된 함수가 다시 호출)
		PostMessage(hwnd, WM_MYMESSAGE1, 0, 0);
		PostMessage(hwnd, WM_CLOSE, 0, 0);
		return 0;

	case WM_CREATE:
		return 0;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;

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