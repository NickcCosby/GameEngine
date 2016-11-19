#pragma once
#include "ImageEngine.h"

class Win32App;

class GameState
{
protected:
	Win32App* program;
	ImageEngine* imageEngine;
public:
	GameState(Win32App* me, int width, int height, HWND hwnd);
	GameState(Win32App* me, ImageEngine* givenImageEngine);
	ImageEngine* getImageEngine()
	{
		return imageEngine;
	}
	virtual void inputReact(WPARAM keyPressed, bool down) = 0;
	virtual void inputReact(int x, int y, bool left) = 0;
};
