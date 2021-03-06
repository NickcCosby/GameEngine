#include "Main.h"

DWORD WINAPI tickThreadProc(LPVOID lpParameter)
{
	Win32App *me = (Win32App*)lpParameter;
	// Give plenty of time for main thread to finish setting up
	Sleep(50);
	ShowWindow(me->getMainWindow(), SW_SHOW);
	// Retrieve the window's DC
	HDC hdc = GetDC(me->getMainWindow());
	// Create DC with shared pixels to variable 'pixels'
	me->setHDCMem(CreateCompatibleDC(hdc));
	HBITMAP hbmOld = (HBITMAP)SelectObject(me->getHDCMem(), me->getImageEngine()->getHbmp());
	// Milliseconds to wait each frame
	int delay = 1000 / 120;
	while (true)
	{
		// Do stuff with pixels
		me->getImageEngine()->present();
		// Draw pixels to window
		BitBlt(hdc, 0, 0, me->getWidth(), me->getHeight(), me->getHDCMem(), 0, 0, SRCCOPY);
		// Wait
		me->getImageEngine()->cleanUp();
	}
	SelectObject(me->getHDCMem(), hbmOld);
	DeleteDC(hdc);
}

LRESULT Win32App::realWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_PAINT:
		/*
		gameState->present();
		if (gameState->getFrontBuffer() != NULL)
		{
			hDC = BeginPaint(mainWindow, &PS);
			for (int ttt = 0; ttt < height; ttt++)
			{
				for (int nnn = 0; nnn < width; nnn++)
				{
					SetPixel(hDC, nnn, ttt, gameState->getFrontBuffer()->getColor(nnn, ttt));
				}
			}
			EndPaint(mainWindow, &PS);
		}
		delete gameState->getFrontBuffer();
		*/
		hDC = BeginPaint(hwnd, &PS);
		// Draw pixels to window when window needs repainting
		BitBlt(hDC, 0, 0, width, height, hDCMem, 0, 0, SRCCOPY);
		EndPaint(hwnd, &PS);
		break;
	case WM_KEYDOWN:
		KeyState ks;
		ks.lparam = lParam;
		if (ks.nPrev == 0)
			gameState->inputReact(wParam, true);
		break;
	case WM_KEYUP:
		gameState->inputReact(wParam, false);
		break;
	case WM_TIMER:
		UpdateWindow(hwnd);
		ShowWindow(hwnd, 5);
		SetTimer(hwnd, NULL, 10, NULL);
		break;
	case WM_CLOSE:
		DestroyWindow(hwnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_LBUTTONDOWN:
		gameState->inputReact(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam), true);
		break;
	default:
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}
	return 0;
}

Win32App::Win32App(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	width = 1600;
	height = 900;
	gameState = new RunningGameState(this, width, height, mainWindow);
	//Step 1: Registering the Window Class
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = 0;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = sizeof(Win32App*);
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = "mainWindow";
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	if (!RegisterClassEx(&wc))
	{
		MessageBox(NULL, "Window Registration Failed!", "Error!",
			MB_ICONEXCLAMATION | MB_OK);;
	}

	// Step 2: Creating the Window
	mainWindow = CreateWindowEx(
		NULL,
		"mainWindow",
		"The title of my window",
		WS_OVERLAPPEDWINDOW,
		0, 0, width, height,
		NULL, NULL, hInstance, NULL);
	SetWindowLongPtr(mainWindow, GWLP_USERDATA,LONG(this));
	if (mainWindow == NULL)
	{
		MessageBox(NULL, "Window Creation Failed!", "Error!",
			MB_ICONEXCLAMATION | MB_OK);
	}

	UpdateWindow(mainWindow);
	hTickThread = CreateThread(NULL, NULL, &tickThreadProc, this, NULL, NULL);
	// Step 3: The Message Loop
	while (GetMessage(&Msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}
}

LRESULT Win32App::WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	Win32App *me = (Win32App*)GetWindowLongPtr(hwnd, GWLP_USERDATA);
	if (me == NULL)
		return DefWindowProc(hwnd, msg, wParam, lParam);
	return me->realWndProc(hwnd, msg, wParam, lParam);
 }

