#pragma once
#include "Main.h"

class Bitmap;
class Showable;
class Pawn;
class GameState
{
private:
	//Bitmap *frontBuffer;
	pixel *frontBuffer;
	Bitmap *allSprites;
	int height;
	int width;
	Showable ***backBuffer;
	Showable ** allShowable;
	Pawn *Player;
	int showableLength;
	HBITMAP hbmp;
public:
	Pawn *getPlayer()
	{
		return Player;
	}
	Bitmap *getFrontBuffer()
	{
		//return frontBuffer;
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
