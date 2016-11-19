#pragma once
#include "Pawn.h"
#include "Pathable.h"
#include "TextEngine.h"

class Bitmap;
class Showable;
class Pawn;
class Background;
class Pathable;

class ImageEngine
{
private:
	pixel *frontBuffer;
	pixel *midBuffer;
	Bitmap *allSprites;
	int height;
	int width;
	Showable **backBuffer;
	Showable **nullBackBuffer;
	Showable ** allShowable;
	int showableLength;
	HBITMAP hbmp;
	Background *activeBackground;
	RECT* allCollisions;
	int collisionLength;
	TextEngine* textEngine;
public:
	void setActiveBackground(Background* newBackground)
	{
		activeBackground = newBackground;
	}
	pixel *getFrontBuffer()
	{
		return frontBuffer;
	}
	Showable ** getBackBuffer()
	{
		return backBuffer;
	}
	Showable **getAllShowable()
	{
		return allShowable;
	}
	int getShowableLength()
	{
		return showableLength;
	}
	int* getShowableLengthPtr()
	{
		return &showableLength;
	}
	HBITMAP getHbmp()
	{
		return hbmp;
	}
	ImageEngine(int givenWidth, int givenHeight, HWND hwnd);
	void present();
	void cleanUp();
	void showText();
};
