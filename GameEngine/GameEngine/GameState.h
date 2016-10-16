#pragma once
#include "Pawn.h"
#include "Pathable.h"

class Bitmap;
class Showable;
class Pawn;
class Background;
class Pathable;

class GameState
{
private:
	pixel *frontBuffer;
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
	Pathable* enemy;
	RECT* allCollisions;
	int collisionLength;
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
};
