#include "std.h"

extern vector<SHAPE> g_shapelist;
extern SHAPE g_curshape;
extern bool g_viewcheck;

LRESULT Create(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	g_curshape.color = RGB(255, 0, 0);
	g_curshape.type = 1;
	g_curshape.pt.x = 100;
	g_curshape.pt.y = 100;
	g_curshape.width = 1;
	g_curshape.size = 50;

	g_viewcheck = FALSE;

	SetTimer(hwnd, 1, 1000, NULL);
	SendMessage(hwnd, WM_TIMER, 1, NULL);
	return 0;
}

LRESULT Destroy(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	KillTimer(hwnd, 1);
	PostQuitMessage(0);
	return 0;
}

LRESULT Paint(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc = BeginPaint(hwnd, &ps);

	for (int i = 0; i < (int)g_shapelist.size(); i++)
	{
		SHAPE sp = g_shapelist[i];

		HPEN pen = CreatePen(PS_SOLID, sp.width, RGB(0, 0, 0));
		HPEN olda = (HPEN)SelectObject(hdc, pen);


		HBRUSH brush = CreateSolidBrush(sp.color);		//펜이나 브러쉬나 폰트나 패턴은 모두 똑같다. //웬만하면 대부분 그림출력은 온페인트에서 한다.
		HBRUSH oldb = (HBRUSH)SelectObject(hdc, brush);

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
			POINT pgon[3] = { sp.pt.x + 50,sp.pt.y + 50,sp.pt.x + 25,sp.pt.y,sp.pt.x,sp.pt.y + 50 };
			Polygon(hdc, pgon, 3);
		}
		DeleteObject(SelectObject(hdc, olda));
		DeleteObject(SelectObject(hdc, oldb));
	}
	

	//좌표 출력========================================================================================================
	if (g_viewcheck == TRUE)
	{
		TCHAR cordi[50];
		wsprintf(cordi, TEXT("%05d:%05d"), g_curshape.pt.x, g_curshape.pt.y);
		TextOut(hdc, 0, 0, cordi, _tcslen(cordi));
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
	CheckMenuItem(hmenu, ID_40014, g_viewcheck == TRUE ? MF_CHECKED : MF_UNCHECKED);

	return 0;
}

LRESULT Command(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	switch (LOWORD(wParam))
	{
	case ID_40001: g_shapelist.clear();					break;
	case ID_40002: g_curshape.color = RGB(0, 255, 0);	break;
	case ID_40003: g_curshape.color = RGB(0, 0, 255);	break;
	case ID_40004: SendMessage(hwnd, WM_CLOSE, 0, 0);	break;
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
			g_viewcheck = TRUE;
		}
		break;
	}
	InvalidateRect(hwnd, 0, TRUE);

	return 0;
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

	g_shapelist.push_back(g_curshape);

	InvalidateRect(hwnd, 0, TRUE);

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

LRESULT MouseMove(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	POINT pt = { LOWORD(lParam), HIWORD(lParam) };	//마우스 좌표를 얻어내는 두번째 방법

	g_curshape.pt = pt;
	RECT rc = { 0,0,200,30 };

	InvalidateRect(hwnd, &rc, TRUE);			//강제 무효화 처리를 통해 다음나올 WM페인트 함수 발동조건인 무효화영역을 미리 발동시켜 바로바로 그림이 나오도록한다. 트루를 해야 화면이 지워짐

	return 0;
}

LRESULT Timer(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	if (wParam == 1)
	{
		SYSTEMTIME st;
		GetLocalTime(&st);
		TCHAR buf[50];
		wsprintf(buf, TEXT("현재날짜 : %d년 %d월 %d일  현재시간 : %d시 %d분 %d초"), st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond);
		SetWindowText(hwnd, buf);
	}
	
	return 0;
}

//LRESULT KeyDown(HWND hwnd, WPARAM wParam, LPARAM lParam)
//{
//	if (lParam & MK_CONTROL)
//	{
//		MessageBox(NULL, TEXT("^^"), TEXT("&&"), MB_OK);
//	}
//	return 0;
//}