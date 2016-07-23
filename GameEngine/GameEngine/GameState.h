#pragma once
#include "Main.h"

class GameState
{
private:
	Bitmap *frontBuffer;
	int height;
	int width;
	Showable ***backBuffer;
	Showable ** allShowable;
	int showableLength;
public:
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
	GameState();
	void present();
};
