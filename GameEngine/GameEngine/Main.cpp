#include "Main.h"

int __stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	Win32App *me = new Win32App(hInstance, hPrevInstance,
		lpCmdLine, nCmdShow);
}