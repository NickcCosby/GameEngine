#include "Win32App.h"

LRESULT Win32App::realWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_PAINT:
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
		break;
	case WM_KEYDOWN:
		KeyState ks;
		ks.lparam = lParam;
		if (ks.nPrev == 0)
		{
			switch (wParam)
			{
			case 0x57:
				gameState->getPlayer()->inputReact('w');
				break;
			case 0x53:
				gameState->getPlayer()->inputReact('s');
				break;
			case 0x41:
				gameState->getPlayer()->inputReact('a');
				break;
			case 0x44:
				gameState->getPlayer()->inputReact('d');
				break;
			}
		}
		break;
	case WM_TIMER:
		SendMessage(hwnd, WM_PAINT, NULL, NULL);
		SetTimer(hwnd, NULL, 10, NULL);
		break;
	case WM_CLOSE:
		DestroyWindow(hwnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}
	return 0;
}

Win32App::Win32App(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	width = 500;
	height = 500;
	gameState = new GameState(width, height);
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
		WS_EX_CLIENTEDGE,
		"mainWindow",
		"The title of my window",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, 500, 500,
		NULL, NULL, hInstance, NULL);
	SetWindowLongPtr(mainWindow, GWLP_USERDATA,LONG(this));
	if (mainWindow == NULL)
	{
		MessageBox(NULL, "Window Creation Failed!", "Error!",
			MB_ICONEXCLAMATION | MB_OK);
	}

	ShowWindow(mainWindow, nCmdShow);
	UpdateWindow(mainWindow);
	SetTimer(mainWindow, NULL, 10, NULL);
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
	me->realWndProc(hwnd, msg, wParam, lParam);
}

