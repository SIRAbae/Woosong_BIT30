//ť,��ť.cpp
#include <Windows.h>
#include <tchar.h>
//proc �⺻ �ڵ�

//����� ���� �޼���
#define WM_MYMESSAGE WM_USER + 100
#define WM_MYMESSAGE1 WM_USER + 200

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_MYMESSAGE:
		SetWindowText(hwnd, TEXT("ù��° �޼���"));
		return 0;

	case WM_MYMESSAGE1:
		SetWindowText(hwnd, TEXT("�ι�° �޼���"));
		return 0;

	case WM_LBUTTONDOWN:
		//��ť �޼���  Send(�Լ����� �Լ� ���ν����� ȣ��� ���¿��� �ٽ� ���ν��� ȣ��)
		SendMessage(hwnd, WM_MYMESSAGE, 0, 0);
		return 0;

	case WM_RBUTTONDOWN:
		//ť �޼���	Post(���ν����� ����� �Ŀ��� ���ν����� ����� �Լ��� �ٽ� ȣ��)
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