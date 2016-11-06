#pragma once
#include "Showable.h"
#include <ctime>

class Letter : Showable
{
public:
	void update(std::clock_t time)
	{

	}
	void kill()
	{
		isDead = true;
	}
	Letter(int startX, int startY, Bitmap *allSprites, Showable **&allShowable, int *showableLength, int width, int height);
	virtual void collide(Showable* otherShowable)
	{

	}
};