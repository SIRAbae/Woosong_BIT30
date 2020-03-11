//Skeleton 코드
#include <Windows.h>
#include <tchar.h>
#include <vector>
#include <stdio.h>
using namespace std;

// 자식의 아이디들
#define IDC_EDIT1      1
#define IDC_COMBO1      2
#define IDC_RADIO1      3
#define IDC_RADIO2      4
#define IDC_CHECKBOX1   5
#define IDC_CHECKBOX2   6
#define IDC_BUTTON1      7
#define IDC_LISTBOX1      8



HWND g_edit1, g_combo1, g_radio1, g_radio2, g_checkbox1, g_checkbox2;
HWND g_button1, g_listbox1;

typedef struct tagMember
{
	TCHAR name[20];
	int age;
	char gender;
	TCHAR hob[20];
}MEMBER;

vector<MEMBER>g_memberlist;


LRESULT OnCreate(HWND hwnd) {

	// 스테틱 컨트롤(제어용이 아닌 뷰어용)
	CreateWindow(TEXT("static"), TEXT("이름"),
		WS_CHILD | WS_VISIBLE | WS_BORDER,
		10, 10, 70, 20, hwnd, (HMENU)0, 0, 0);

	CreateWindow(TEXT("static"), TEXT("나이"),
		WS_CHILD | WS_VISIBLE | WS_BORDER,
		10, 40, 70, 20, hwnd, (HMENU)0, 0, 0);

	CreateWindow(TEXT("static"), TEXT("성별"),
		WS_CHILD | WS_VISIBLE | WS_BORDER,
		10, 70, 70, 20, hwnd, (HMENU)0, 0, 0);

	CreateWindow(TEXT("static"), TEXT("취미"),
		WS_CHILD | WS_VISIBLE | WS_BORDER,
		10, 100, 70, 20, hwnd, (HMENU)0, 0, 0);


	// 에디트 컨트롤   page 128
	g_edit1 = CreateWindow(TEXT("edit"), TEXT(""),      // 키값, 텍스트
		WS_CHILD | WS_VISIBLE | WS_BORDER,            // 자식이라는걸 알려주는것, 쇼윈도우관련(해야지 눈에 보임), 테두리
		90, 10, 200, 20, hwnd, (HMENU)IDC_EDIT1, 0, 0);   // 자식의 아이디


	 // 콤보박스 컨트롤( 리스트박스 컨트롤과 유사)
	g_combo1 = CreateWindow(TEXT("combobox"), TEXT(""),
		WS_CHILD | WS_VISIBLE | WS_BORDER | CBS_DROPDOWNLIST,
		90, 40, 200, 200, hwnd, (HMENU)IDC_COMBO1, 0, 0);


	//라디오 버튼 컨트롤(다수 중 하나를 선택)
	g_radio1 = CreateWindow(TEXT("button"), TEXT("남자"),
		WS_CHILD | WS_VISIBLE | WS_BORDER | BS_AUTORADIOBUTTON,
		90, 70, 90, 20, hwnd, (HMENU)IDC_RADIO1, 0, 0);

	g_radio2 = CreateWindow(TEXT("button"), TEXT("여자"),
		WS_CHILD | WS_VISIBLE | WS_BORDER | BS_AUTORADIOBUTTON,
		200, 70, 90, 20, hwnd, (HMENU)IDC_RADIO2, 0, 0);


	// 체크박스 컨트롤(다수를 선택 가능)
	g_checkbox1 = CreateWindow(TEXT("button"), TEXT("여행"),
		WS_CHILD | WS_VISIBLE | WS_BORDER | BS_AUTOCHECKBOX,
		90, 100, 90, 20, hwnd, (HMENU)IDC_CHECKBOX1, 0, 0);

	g_checkbox2 = CreateWindow(TEXT("button"), TEXT("독서"),
		WS_CHILD | WS_VISIBLE | WS_BORDER | BS_AUTOCHECKBOX,
		200, 100, 90, 20, hwnd, (HMENU)IDC_CHECKBOX2, 0, 0);

	// 버튼 컨트롤
	g_button1 = CreateWindow(TEXT("button"), TEXT("전달"),
		WS_CHILD | WS_VISIBLE | WS_BORDER,
		200, 130, 90, 20, hwnd, (HMENU)IDC_BUTTON1, 0, 0);

	//리스트 컨트롤
	g_listbox1 = CreateWindow(TEXT("listbox"), TEXT("남자"),
		WS_CHILD | WS_VISIBLE | WS_BORDER,
		300, 10, 300, 200, hwnd, (HMENU)IDC_LISTBOX1, 0, 0);

	//컨트롤 초기화
	// 부모 -> 콤보박스
	SendMessage(g_combo1, CB_ADDSTRING, 0, (LPARAM)TEXT("10"));
	SendMessage(g_combo1, CB_ADDSTRING, 0, (LPARAM)TEXT("20"));
	SendMessage(g_combo1, CB_ADDSTRING, 0, (LPARAM)TEXT("30"));


	return 0;

}

LRESULT OnDestroy(HWND hwnd, WPARAM wParam, LPARAM lParam) {


	PostQuitMessage(0);

	return 0;

}

void OnNotifyEdit(HWND hwnd, WPARAM wParam) {

	if (HIWORD(wParam) == EN_CHANGE) {   // EN_CHANGE -> 문자열이 변경될때마다...

		TCHAR temp[256];
		GetWindowText(g_edit1, temp, sizeof(temp));

		// 타이틀바 출력
		SetWindowText(hwnd, temp);
	}

}

void OnNotifyCombo(HWND hwnd, WPARAM wParam) {

	if (HIWORD(wParam) == CBN_SELCHANGE) {   // CBN_SELCHANGE -> 선택을 변경될때마다...

	   // 선택된 인덱스
		int sel = SendMessage(g_combo1, CB_GETCURSEL, 0, 0);

		// 그 인덱스가 가지고 있는 문자열 획득
		TCHAR temp[256];
		SendMessage(g_combo1, CB_GETLBTEXT, sel, (LPARAM)temp);

		// 타이틀바 출력
		SetWindowText(hwnd, temp);
	}

}

void OnNotifyRadio1(HWND hwnd, WPARAM wParam) {

	if (HIWORD(wParam) == BN_CLICKED) {      // 선택이 변경될때마다...

		TCHAR temp[256];
		GetWindowText(g_radio1, temp, sizeof(temp));

		// 타이틀바 출력
		SetWindowText(hwnd, temp);

	}

}

void OnNotifyRadio2(HWND hwnd, WPARAM wParam) {

	if (HIWORD(wParam) == BN_CLICKED) {      // 선택이 변경될때마다...

		TCHAR temp[256];
		GetWindowText(g_radio2, temp, sizeof(temp));

		// 타이틀바 출력
		SetWindowText(hwnd, temp);

	}

}

void OnNotifyCheck1(HWND hwnd, WPARAM wParam) {

	//체크박스를 누를 때 마다 눌러있는 체크박스를 찾는다.
	if (HIWORD(wParam) == BN_CLICKED) {      // 선택이 변경될때마다...

		TCHAR arr[256] = TEXT("");
		if (SendMessage(g_checkbox1, BM_GETCHECK, 0, 0) == BST_CHECKED) {

			TCHAR str[20];
			GetWindowText(g_checkbox1, str, sizeof(str));
			_tcscpy_s(arr, str);   // 카피

		}

		if (SendMessage(g_checkbox2, BM_GETCHECK, 0, 0) == BST_CHECKED) {

			TCHAR str[20];
			GetWindowText(g_checkbox2, str, sizeof(str));
			_tcscat_s(arr, str);   // 붙혀넣기

		}

		SetWindowText(hwnd, arr);

	}

}

void AddListBox(HWND hwnd)
{
	

	for (int i = 0; i < (int)g_memberlist.size(); i++)
	{
		MEMBER mem = g_memberlist[i];

		TCHAR str[256];
		wsprintf(str, TEXT("%s,%d,%c,%s"), mem.name, mem.age, mem.gender, mem.hob);

		SendMessage(g_listbox1, LB_ADDSTRING, 0, (LPARAM)str);
	}
}

void OnNotifyButton1(HWND hwnd, WPARAM wParam)
{
	//버튼의 통지메세지는 하나... == 클릭
	//저장 알고리즘 
	MEMBER member;
	
	//이름
	GetWindowText(g_edit1, member.name, sizeof(member.name));

	//나이
	TCHAR temp[256];
	int sel = SendMessage(g_combo1, CB_GETCURSEL, 0, 0);
	SendMessage(g_combo1, CB_GETLBTEXT, sel, (LPARAM)temp);
	member.age = _ttoi(temp);	//stdio.h

	//성별
	if (SendMessage(g_checkbox2, BM_GETCHECK, 0, 0) == BST_CHECKED)
	{
		member.gender = 'm';
	}
	else
		member.gender = 'f';

	//취미
	
	TCHAR arr[256] = TEXT("");
	if (SendMessage(g_checkbox1, BM_GETCHECK, 0, 0) == BST_CHECKED) {

		TCHAR str[20];
		GetWindowText(g_checkbox1, str, sizeof(str));
		_tcscpy_s(member.hob, str);   // 카피

	}

	if (SendMessage(g_checkbox2, BM_GETCHECK, 0, 0) == BST_CHECKED) {

		TCHAR str[20];
		GetWindowText(g_checkbox2, str, sizeof(str));
		_tcscat_s(member.hob, str);   // 붙혀넣기
	}

	g_memberlist.push_back(member);

	AddListBox(hwnd);

}

LRESULT OnCommand(HWND hwnd, WPARAM wParam, LPARAM lParam) {

	// page 129 ID 조사
	switch (LOWORD(wParam)) {

	case IDC_EDIT1:
		OnNotifyEdit(hwnd, wParam);
		break;
	case IDC_COMBO1:
		OnNotifyCombo(hwnd, wParam);
		break;
	case IDC_RADIO1:
		OnNotifyRadio1(hwnd, wParam);
		break;
	case IDC_RADIO2:
		OnNotifyRadio2(hwnd, wParam);
		break;
	case IDC_CHECKBOX1:
		OnNotifyCheck1(hwnd, wParam);
		break;
	case IDC_CHECKBOX2:
		OnNotifyCheck1(hwnd, wParam);
		break;
	case IDC_BUTTON1:
		OnNotifyButton1(hwnd, wParam);
		break;
	}

	return 0;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {

	switch (msg) {
	case WM_CREATE:
		return OnCreate(hwnd);
	case WM_COMMAND:
		return OnCommand(hwnd, wParam, lParam);
	case WM_DESTROY:
		return OnDestroy(hwnd, wParam, lParam);
	}
	return DefWindowProc(hwnd, msg, wParam, lParam);

}

int WINAPI _tWinMain(HINSTANCE hInst, HINSTANCE hPrev, LPTSTR lpCmdLine, int nShowCmd) {

	//1. 윈도우 클래스 만들기
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

	//2. 등록(레지스트리에)
	RegisterClass(&wc);

	//3. 윈도우 창 만들기
	HWND hwnd = CreateWindowEx(0,      //WS_EX_TOPMOST
		TEXT("first"),               //클래스 명
		TEXT("Hello"),               //캡션바 내용
		WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0, CW_USEDEFAULT, 0,   //초기 위치
		0, 0,            //부모 윈도우 핸들, 메뉴 핸들
		hInst,            //WinMain의 1번쨰 파라미터 (exe 주소)
		0);               //생성 인자

	 //4. 윈도우 보여주기
	ShowWindow(hwnd, SW_SHOW);
	UpdateWindow(hwnd);

	//5. Message
	MSG msg;
	while (GetMessage(&msg, 0, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;

}