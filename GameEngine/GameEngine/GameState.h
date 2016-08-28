#pragma once
#include "Main.h"

class Bitmap;
class Showable;
class Pawn;
class Background;
class GameState
{
private:
	pixel *frontBuffer;
	Bitmap *allSprites;
	int height;
	int width;
	Showable ***backBuffer;
	Showable ** allShowable;
	Pawn *player;
	int showableLength;
	HBITMAP hbmp;
	Background *activeBackground;
public:
	Pawn *getPlayer()
	{
		return player;
	}
	pixel *getFrontBuffer()
	{
		return frontBuffer;
	}
	Showable *** getBackBuffer()
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
