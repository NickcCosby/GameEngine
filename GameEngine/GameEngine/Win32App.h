#pragma once
#include "GameState.h"

class Bitmap;
class Showable;
class ImageEngine;
class GameState;

class Win32App
{
private:
	WNDCLASSEX wc;
	HWND mainWindow;
	MSG Msg;
	LRESULT realWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
	HDC hDC;
	HDC hDCMem;
	PAINTSTRUCT PS;
	GameState *gameState;
	HANDLE hTickThread;
	int width;
	int height;
public:
	Win32App(HINSTANCE hInstance, HINSTANCE hPrevInstance,
		LPSTR lpCmdLine, int nCmdShow);

	static LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
	HWND getMainWindow()
	{
		return mainWindow;
	}
	HDC getHDCMem()
	{
		return hDCMem;
	}
	void setHDCMem(HDC newHDC)
	{
		hDCMem = newHDC;
	}
	ImageEngine *getImageEngine()
	{
		return gameState->getImageEngine();
	}
	int getWidth()
	{
		return width;
	}
	int getHeight()
	{
		return height;
	}
};
