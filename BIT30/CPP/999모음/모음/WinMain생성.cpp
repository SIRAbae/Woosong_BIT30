//WinMain.cpp
#include <Windows.h>
#include <tchar.h>
int WINAPI _tWinMain(HINSTANCE hlnst, HINSTANCE hpev, LPTSTR lpCmdLine, int nShowCmd)
{
	//================================================================
	//1. 윈도우 클래스 생성
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = DefWindowProc;	 //메세지처리함수
	wcex.cbClsExtra = 0; //예약
	wcex.cbWndExtra = 0; //예약
	wcex.hInstance = hlnst; //자신의 인스턴스 등록
	wcex.hIcon = LoadIcon(0, IDI_APPLICATION);//미리 등록된..
	wcex.hCursor = LoadCursor(0, IDC_ARROW);//미리 등록된
	wcex.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);//미리 등록된..
	wcex.lpszMenuName = 0;
	wcex.lpszClassName = TEXT("FIRST");// 등록키
	wcex.hIconSm = 0; //예약

	//2. 윈도우 클래스 레지스티리에 등록
	RegisterClassEx(&wcex);
	//3. 윈도우 생성(<------- MainWindow)
	//처음 만드는 객체(UI객체)
	HWND hWnd;
	//윈도우 핸들
	hWnd = CreateWindow(TEXT("FIRST"), TEXT("타이틀바"), WS_OVERLAPPEDWINDOW,	//윈도우속성
		0, 0, 300, 200,		//시작위치,사이즈
		0, 0, hlnst, 0);
	//4. 윈도우 화면 출력
	//ShowWindow(hwnd, SW_NORMAL);
	ShowWindow(hWnd, nShowCmd);
	//================================================================

	MessageBox(0, TEXT("Hello,API"), TEXT("First"), MB_OK);
	return 0;
}