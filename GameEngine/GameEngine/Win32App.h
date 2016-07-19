#pragma once
#include "Main.h"

class Bitmap;
class Showable;

class Win32App
{
private:
	WNDCLASSEX wc;
	HWND mainWindow;
	MSG Msg;
	LRESULT realWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
	HDC hDC;
	PAINTSTRUCT PS;
	Bitmap *backBuffer;
	Bitmap *frontBuffer;
	int height;
	int width;
	Showable ***depthcheck;
	Showable ** allShowable;
public:
	Win32App(HINSTANCE hInstance, HINSTANCE hPrevInstance,
		LPSTR lpCmdLine, int nCmdShow);
	static LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
	void present(); //swaps backBuffer to front buffer
};
