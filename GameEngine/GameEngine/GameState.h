#pragma once
#include "Pawn.h"
#include "Pathable.h"
#include "TextEngine.h"

class Bitmap;
class Showable;
class Pawn;
class Background;
class Pathable;

class GameState
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
	Pawn *player;
	int showableLength;
	HBITMAP hbmp;
	Background *activeBackground;
	Ai* enemy;
	RECT* allCollisions;
	int collisionLength;
	TextEngine* textEngine;
public:
	Pawn *getPlayer()
	{
		return player;
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
	HBITMAP getHbmp()
	{
		return hbmp;
	}
	GameState(int givenWidth, int givenHeight, HWND hwnd);
	void present();
	void cleanUp();
	void showText();
};
