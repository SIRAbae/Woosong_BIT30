//Textout.cpp
#include <Windows.h>
#include <tchar.h>
//proc 기본 코드
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_LBUTTONDOWN:
	{
		//사각형 출력
		//HDC hdc = GetDC(hwnd);	//클라이언트 영역
		HDC hdc = GetDC(hwnd);
		SetTextAlign(hdc, TA_UPDATECP);
		TextOut(hdc, 200, 200, TEXT("Buautiful Korea"), 15);
		TextOut(hdc, 200, 220, TEXT("is My"), 5);
		TextOut(hdc, 200, 240, TEXT("Lovely Home Country"), 19);


		ReleaseDC(hwnd, hdc);

	}
	return 0;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwnd, &ps);
		SetTextAlign(hdc, TA_CENTER);
		TextOut(hdc, 200, 60, TEXT("Buautiful Korea"), 15);
		TextOut(hdc, 200, 80, TEXT("is My"), 5);
		TextOut(hdc, 200, 100, TEXT("Lovely Home Country"), 19);
		EndPaint(hwnd, &ps);


	}
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

	/*
	MSG msg;
	while (true)
	{
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
				break;
			DispatchMessage(&msg);
		}
		else
		{
			HDC hdc = GetDC(hwnd);
			SetPixel(hdc, rand() % 500, rand() % 400, RGB(rand() % 256, rand() % 256, rand() % 256));
			ReleaseDC(hwnd, hdc);
		}

	}
*/
}