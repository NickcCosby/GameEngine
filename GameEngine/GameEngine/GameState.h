#pragma once
#include "Main.h"

class Bitmap;
class Showable;
class Pawn;
class GameState
{
private:
	Bitmap *frontBuffer;
	Bitmap *allSprites;
	int height;
	int width;
	Showable ***backBuffer;
	Showable ** allShowable;
	Pawn *Player;
	int showableLength;
public:
	Pawn *getPlayer()
	{
		return Player;
	}
	Bitmap *getFrontBuffer()
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
	GameState(int givenWidth, int givenHeight);
	void present();
	void cleanUp();
};
