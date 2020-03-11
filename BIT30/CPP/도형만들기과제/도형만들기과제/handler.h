#pragma once
LRESULT OnCreate(HWND hwnd, WPARAM wparam, LPARAM IParam);
LRESULT OnDestroy(HWND hwnd, WPARAM wparam, LPARAM IParam);
LRESULT OnPaint(HWND hwnd, WPARAM wParam, LPARAM lParam);
LRESULT OnContextMenu(HWND hwnd, WPARAM wParam, LPARAM lParam);
LRESULT OnCommand(HWND hwnd, WPARAM wParam, LPARAM lParam);
LRESULT OnInitMenuPopup(HWND hwnd, WPARAM wParam, LPARAM lParam);
LRESULT OnLButtonDown(HWND hwnd, WPARAM wParam, LPARAM lParam);
LRESULT Create(HWND hwnd, WPARAM wParam, LPARAM lParam);
LRESULT OnTimer(HWND hwnd, WPARAM wParam, LPARAM lParam);
LRESULT OnMouseMove(HWND hwnd, WPARAM wParam, LPARAM lParam);
