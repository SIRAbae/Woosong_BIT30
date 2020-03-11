#pragma once


//3.도형구조체의 정의
typedef struct tagSHAPE
{
	int type;
	int width;
	int size;
	COLORREF color;
	POINT pt;
}SHAPE;

LRESULT Create(HWND hwnd, WPARAM wParam, LPARAM lParam);
LRESULT Destroy(HWND hwnd, WPARAM wParam, LPARAM lParam);
LRESULT Paint(HWND hwnd, WPARAM wParam, LPARAM lParam);
LRESULT InitMenuPopup(HWND hwnd, WPARAM wParam, LPARAM lParam);
LRESULT ContextMenu(HWND hwnd, WPARAM wParam, LPARAM lParam);
LRESULT Command(HWND hwnd, WPARAM wParam, LPARAM lParam);
LRESULT LButtonDown(HWND hwnd, WPARAM wParam, LPARAM lParam);
LRESULT MouseMove(HWND hwnd, WPARAM wParam, LPARAM lParam);
LRESULT Timer(HWND hwnd, WPARAM wParam, LPARAM lParam);
