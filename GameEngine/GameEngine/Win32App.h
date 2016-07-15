#pragma once
#include "Main.h"

class Win32App
{
private:
	WNDCLASSEX wc;
	HWND mainWindow;
	MSG Msg;
	LRESULT realWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
	HDC hDC;
	PAINTSTRUCT PS;
public:
	Win32App(HINSTANCE hInstance, HINSTANCE hPrevInstance,
		LPSTR lpCmdLine, int nCmdShow);
	static LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
};
