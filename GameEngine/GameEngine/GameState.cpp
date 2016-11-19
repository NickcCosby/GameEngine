#include "Main.h"

GameState::GameState(Win32App* me, int width, int height, HWND hwnd)
{
	program = me;
	imageEngine = new ImageEngine(width, height, hwnd);
}

GameState::GameState(Win32App* me, ImageEngine* givenImageEngine)
{
	program = me;
	imageEngine = givenImageEngine;
}
