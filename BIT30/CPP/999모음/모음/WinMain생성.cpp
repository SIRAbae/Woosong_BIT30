//WinMain.cpp
#include <Windows.h>
#include <tchar.h>
int WINAPI _tWinMain(HINSTANCE hlnst, HINSTANCE hpev, LPTSTR lpCmdLine, int nShowCmd)
{
	//================================================================
	//1. ������ Ŭ���� ����
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = DefWindowProc;	 //�޼���ó���Լ�
	wcex.cbClsExtra = 0; //����
	wcex.cbWndExtra = 0; //����
	wcex.hInstance = hlnst; //�ڽ��� �ν��Ͻ� ���
	wcex.hIcon = LoadIcon(0, IDI_APPLICATION);//�̸� ��ϵ�..
	wcex.hCursor = LoadCursor(0, IDC_ARROW);//�̸� ��ϵ�
	wcex.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);//�̸� ��ϵ�..
	wcex.lpszMenuName = 0;
	wcex.lpszClassName = TEXT("FIRST");// ���Ű
	wcex.hIconSm = 0; //����

	//2. ������ Ŭ���� ������Ƽ���� ���
	RegisterClassEx(&wcex);
	//3. ������ ����(<------- MainWindow)
	//ó�� ����� ��ü(UI��ü)
	HWND hWnd;
	//������ �ڵ�
	hWnd = CreateWindow(TEXT("FIRST"), TEXT("Ÿ��Ʋ��"), WS_OVERLAPPEDWINDOW,	//������Ӽ�
		0, 0, 300, 200,		//������ġ,������
		0, 0, hlnst, 0);
	//4. ������ ȭ�� ���
	//ShowWindow(hwnd, SW_NORMAL);
	ShowWindow(hWnd, nShowCmd);
	//================================================================

	MessageBox(0, TEXT("Hello,API"), TEXT("First"), MB_OK);
	return 0;
}