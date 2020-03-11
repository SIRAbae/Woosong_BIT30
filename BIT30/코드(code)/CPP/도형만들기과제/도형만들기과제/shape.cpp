#include "std.h"

//4.�������� ����
extern vector<SHAPE> g_shapelist;
extern SHAPE g_curshape;
bool g_viewcheck;



//5. �������� �ʱ�ȭ
LRESULT Create(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	g_curshape.color = RGB(255, 0, 0);
	g_curshape.type = 1;
	g_curshape.pt.x = 100;
	g_curshape.pt.y = 100;
	g_curshape.width = 1;
	g_curshape.size = 50;
	return 0;
}


//LRESULT OnContextMenu(HWND hwnd, WPARAM wParam, LPARAM lParam)
//{
//	HMENU hmenu = GetMenu(hwnd);
//	HMENU hsub = GetSubMenu(hmenu, 1);
//
//	POINT pt = { LOWORD(lParam), HIWORD(lParam) };
//	g_curshape.pt = pt;
//	TrackPopupMenu(hsub, TPM_LEFTBUTTON, g_curshape.pt.x, g_curshape.pt.y, 0, hwnd, 0);
//
//	return 0;
//}

//11.��ǥ
LRESULT MouseMove(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	POINT pt1 = { LOWORD(lParam), HIWORD(lParam) };
	g_curshape.pt = pt1;
	RECT rc = { 0,0,200,30 };
	InvalidateRect(hwnd, &rc, TRUE);
	return 0;
}

LRESULT Destroy(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	PostQuitMessage(0);
	return 0;
}

LRESULT Paint(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc = BeginPaint(hwnd, &ps);



	HPEN pen = CreatePen(PS_SOLID, g_curshape.width, RGB(0, 0, 0)); //�� ������
	HPEN old = (HPEN)SelectObject(hdc, pen);



	DeleteObject(SelectObject(hdc, old));

	HBRUSH brush = CreateSolidBrush(g_curshape.color);		//���̳� �귯���� ��Ʈ�� ������ ��� �Ȱ���. //�����ϸ� ��κ� �׸������ ������Ʈ���� �Ѵ�.
	HBRUSH oldb = (HBRUSH)SelectObject(hdc, brush);		//HBRUSH : ������ ���� ä��� ���� (GDI������Ʈ)

	//9. ��������
	for (int i = 0; i < (int)g_shapelist.size(); i++)
	{
		SHAPE sp = g_shapelist[i];

		if (sp.type == 1)
		{
			Rectangle(hdc, sp.pt.x, sp.pt.y, sp.pt.x + sp.size, sp.pt.y + sp.size);
		}
		else if (sp.type == 2)
		{
			Ellipse(hdc, sp.pt.x, sp.pt.y, sp.pt.x + sp.size, sp.pt.y + sp.size);
		}
		else if (sp.type == 3)
		{
			/*MoveToEx(hdc, sp.pt.x, sp.pt.y + 50, NULL);
			LineTo(hdc, sp.pt.x + 50, sp.pt.y + 50);
			LineTo(hdc, sp.pt.x + 25, sp.pt.y);
			LineTo(hdc, sp.pt.x, sp.pt.y + 50);*/
			POINT pgon[3] = { sp.pt.x,sp.pt.y + 50,sp.pt.x + 25,sp.pt.y,sp.pt.x + 50,sp.pt.y + 50 };
			Polygon(hdc, pgon, 3);

		}

	}

	//GDI �����

	DeleteObject(SelectObject(hdc, old));
	DeleteObject(SelectObject(hdc, oldb));
	//=================================================================================================================

	//��ǥ ���========================================================================================================
	if (g_viewcheck == TRUE)
	{
		TCHAR arr[20];
		wsprintf(arr, TEXT("%05d : %05d"), g_curshape.pt.x, g_curshape.pt.y);
		TextOut(hdc, 0, 0, arr, _tcslen(arr));
	}




	EndPaint(hwnd, &ps);
	return 0;
}

LRESULT InitMenuPopup(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	HMENU hmenu = (HMENU)wParam;

	EnableMenuItem(hmenu, ID_40005, g_curshape.type == 1 ? MF_GRAYED : MF_ENABLED);
	EnableMenuItem(hmenu, ID_40006, g_curshape.type == 2 ? MF_GRAYED : MF_ENABLED);
	EnableMenuItem(hmenu, ID_40007, g_curshape.type == 3 ? MF_GRAYED : MF_ENABLED);
	EnableMenuItem(hmenu, ID_40008, g_curshape.color == RGB(255, 0, 0) ? MF_GRAYED : MF_ENABLED);
	EnableMenuItem(hmenu, ID_40009, g_curshape.color == RGB(0, 255, 0) ? MF_GRAYED : MF_ENABLED);
	EnableMenuItem(hmenu, ID_40010, g_curshape.color == RGB(0, 0, 255) ? MF_GRAYED : MF_ENABLED);
	EnableMenuItem(hmenu, ID_40011, g_curshape.width == 1 ? MF_GRAYED : MF_ENABLED);
	EnableMenuItem(hmenu, ID_40012, g_curshape.width == 3 ? MF_GRAYED : MF_ENABLED);
	EnableMenuItem(hmenu, ID_40013, g_curshape.width == 5 ? MF_GRAYED : MF_ENABLED);
	EnableMenuItem(hmenu, ID_40014, g_viewcheck == TRUE ? MF_CHECKED : MF_UNCHECKED);
	//üũ ��������
	//
	return 0;
}

LRESULT Command(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	switch (LOWORD(wParam))
	{
	case ID_40001: g_shapelist.clear();					break;
	case ID_40002: g_curshape.color = RGB(0, 255, 0);	break;
	case ID_40003: g_curshape.color = RGB(0, 0, 255);	break;
	case ID_40004: SendMessage(hwnd, WM_CLOSE, 0, 0);	break;  //8.���α׷�����
	case ID_40005: g_curshape.type = 1;					break;
	case ID_40006: g_curshape.type = 2;					break;
	case ID_40007: g_curshape.type = 3;					break;
	case ID_40008: g_curshape.color = RGB(255, 0, 0);	break;
	case ID_40009: g_curshape.color = RGB(0, 255, 0);	break;
	case ID_40010: g_curshape.color = RGB(0, 0, 255);	break;
	case ID_40011: g_curshape.width = 1;				break;
	case ID_40012: g_curshape.width = 3;				break;
	case ID_40013: g_curshape.width = 5;				break;
	case ID_40014:
		if (g_viewcheck == TRUE)
		{
			g_viewcheck = FALSE;
		}
		else if (g_viewcheck == FALSE)
		{
			g_viewcheck == TRUE;
		} break;

		InvalidateRect(hwnd, 0, TRUE);

		return 0;
	}
}

LRESULT ContextMenu(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	HMENU hmenu = GetMenu(hwnd);
	HMENU hsub = GetSubMenu(hmenu, 1);

	POINT pt = { LOWORD(lParam), HIWORD(lParam) };

	TrackPopupMenu(hsub, TPM_LEFTBUTTON, pt.x, pt.y, 0, hwnd, 0);

	return 0;
}

LRESULT LButtonDown(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	g_curshape.pt = { LOWORD(lParam), HIWORD(lParam) };

	g_shapelist.push_back(g_curshape); //13.Ŭ���� ����

	InvalidateRect(hwnd, 0, TRUE);  //13.��ȿȭ page 51

	if (wParam & MK_CONTROL)
	{
		g_shapelist.pop_back();
		if (g_shapelist.size() <= 0)
		{
			return 0;
		}
		g_shapelist.pop_back();
	}
	return 0;

}


/*

�޴��ٿ� �ð����
LRESULT Timer(HWND hwnd, WPARAM wParam, LPARAM lParam) {

   if (wParam == 1) {
	  SYSTEMTIME st;
	  GetSystemTime(&st);
	  GetLocalTime(&st);
	  TCHAR buf[50];
	  wsprintf(buf, TEXT("����ð� : %d�� %d�� %d�� %d�� %d�� %d��"),
		 st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond);
	  SetWindowText(hwnd, buf);

   }
   return 0;
}

*/