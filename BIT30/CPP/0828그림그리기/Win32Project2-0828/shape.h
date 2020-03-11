#pragma once
#include <Windows.h>
#include <tchar.h>

typedef struct tagSHAPE
{
	POINT pt;
	int type;
	COLORREF color;
	int width;
	int size;

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
//LRESULT KeyDown(HWND hwnd, WPARAM wParam, LPARAM lParam);