//����,cpp

#include <Windows.h>
#include <tchar.h>

int WINAPI _tWinMain(HINSTANCE hlnst, HINSTANCE hpev, LPTSTR lpCmdLine, int nShowCmd) {

	//================================================================
	//1. ������ Ŭ���� ����
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = DefWindowProc;    //�޼���ó���Լ�
	wcex.cbClsExtra = 0; //����
	wcex.cbWndExtra = 0; //����
	wcex.hInstance = hlnst; //�ڽ��� �ν��Ͻ� ���
	wcex.hIcon = LoadIcon(0, IDI_APPLICATION);//�̸� ��ϵ�..
	wcex.hCursor = LoadCursor(0, IDC_ARROW);//�̸� ��ϵ�
	wcex.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);//�̸� ��ϵ�..
	wcex.lpszMenuName = 0;
	wcex.lpszClassName = TEXT("START");// ���Ű
	wcex.hIconSm = 0; //����

	//2. ������ Ŭ���� ������Ƽ���� ���
	RegisterClassEx(&wcex);

	//3. ������ ����(<------- MainWindow)
	//ó�� ����� ��ü(UI��ü)
	HWND hwnd;

	//������ �ڵ�
	hwnd = CreateWindow(TEXT("START"), TEXT("����"),
		WS_OVERLAPPEDWINDOW,   //������Ӽ�
		525, 200, 300, 200,      //������ġ,������
		0, 0, hlnst, 0);

	//4. ������ ȭ�� ���
	//ShowWindow(hwnd, SW_NORMAL);
	ShowWindow(hwnd, nShowCmd);

	//================================================================

	if (hwnd == 0) {
		MessageBox(0, _TEXT("���� �ڵ��� ���� �� �����ϴ�."),
			_TEXT("�˸�"), MB_OK | MB_ICONERROR);
		return 0;
	}
	else {
		TCHAR temp[20];
		wsprintf(temp, _TEXT("���� �ڵ� : %d"), hwnd);
		MessageBox(0, temp, _TEXT("�˸�"), MB_OK);
	}


	//���� Ŭ���� �̸� �� Rect ���
	TCHAR name[60];
	RECT rcCalc;
	GetClassName(hwnd, name, sizeof(name));
	GetWindowRect(hwnd, &rcCalc);

	//�������
	TCHAR info[265];
	wsprintf(info, _TEXT("Ŭ������ : %s\n��ġ : %d, %d ~ %d, %d"), name,
		rcCalc.left, rcCalc.top, rcCalc.right, rcCalc.bottom);
	MessageBox(0, info, TEXT("���� ����"), MB_OK);

	//���� �̵��ϱ�
	MoveWindow(hwnd, 10, 10, rcCalc.right - rcCalc.left, rcCalc.bottom - rcCalc.top, TRUE);

	//���� �����
	MessageBox(0, _TEXT("����"), TEXT("���� �����"), MB_OK);
	ShowWindow(hwnd, SW_HIDE);

	//���� ���̱�
	MessageBox(0, _TEXT("����"), TEXT("���� ���̱�"), MB_OK);
	ShowWindow(hwnd, SW_SHOW);

	//���� �����ϱ�
	MessageBox(0, _TEXT("����"), TEXT("���� �����ϱ�"), MB_OK);
	SendMessage(hwnd, WM_CLOSE, 0, 0);

	return 0;

}