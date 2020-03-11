//계산기,cpp

#include <Windows.h>
#include <tchar.h>

int WINAPI _tWinMain(HINSTANCE hlnst, HINSTANCE hpev, LPTSTR lpCmdLine, int nShowCmd) {

	//================================================================
	//1. 윈도우 클래스 생성
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = DefWindowProc;    //메세지처리함수
	wcex.cbClsExtra = 0; //예약
	wcex.cbWndExtra = 0; //예약
	wcex.hInstance = hlnst; //자신의 인스턴스 등록
	wcex.hIcon = LoadIcon(0, IDI_APPLICATION);//미리 등록된..
	wcex.hCursor = LoadCursor(0, IDC_ARROW);//미리 등록된
	wcex.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);//미리 등록된..
	wcex.lpszMenuName = 0;
	wcex.lpszClassName = TEXT("START");// 등록키
	wcex.hIconSm = 0; //예약

	//2. 윈도우 클래스 레지스티리에 등록
	RegisterClassEx(&wcex);

	//3. 윈도우 생성(<------- MainWindow)
	//처음 만드는 객체(UI객체)
	HWND hwnd;

	//윈도우 핸들
	hwnd = CreateWindow(TEXT("START"), TEXT("계산기"),
		WS_OVERLAPPEDWINDOW,   //윈도우속성
		525, 200, 300, 200,      //시작위치,사이즈
		0, 0, hlnst, 0);

	//4. 윈도우 화면 출력
	//ShowWindow(hwnd, SW_NORMAL);
	ShowWindow(hwnd, nShowCmd);

	//================================================================

	if (hwnd == 0) {
		MessageBox(0, _TEXT("계산기 핸들을 얻을 수 없습니다."),
			_TEXT("알림"), MB_OK | MB_ICONERROR);
		return 0;
	}
	else {
		TCHAR temp[20];
		wsprintf(temp, _TEXT("계산기 핸들 : %d"), hwnd);
		MessageBox(0, temp, _TEXT("알림"), MB_OK);
	}


	//계산기 클래스 이름 및 Rect 얻기
	TCHAR name[60];
	RECT rcCalc;
	GetClassName(hwnd, name, sizeof(name));
	GetWindowRect(hwnd, &rcCalc);

	//정보출력
	TCHAR info[265];
	wsprintf(info, _TEXT("클래스명 : %s\n위치 : %d, %d ~ %d, %d"), name,
		rcCalc.left, rcCalc.top, rcCalc.right, rcCalc.bottom);
	MessageBox(0, info, TEXT("계산기 정보"), MB_OK);

	//계산기 이동하기
	MoveWindow(hwnd, 10, 10, rcCalc.right - rcCalc.left, rcCalc.bottom - rcCalc.top, TRUE);

	//계산기 숨기기
	MessageBox(0, _TEXT("계산기"), TEXT("계산기 숨기기"), MB_OK);
	ShowWindow(hwnd, SW_HIDE);

	//계산기 보이기
	MessageBox(0, _TEXT("계산기"), TEXT("계산기 보이기"), MB_OK);
	ShowWindow(hwnd, SW_SHOW);

	//계산기 종료하기
	MessageBox(0, _TEXT("계산기"), TEXT("계산기 종료하기"), MB_OK);
	SendMessage(hwnd, WM_CLOSE, 0, 0);

	return 0;

}