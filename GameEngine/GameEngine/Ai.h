#pragma once
#include "Pathable.h"

class Pathable;

class Ai : public Pathable
{
protected:

public:
	Ai(int startX, int startY, Bitmap *allSprites, Showable **&allShowable, int *showableLength, int width, int height);
	void collide(Showable* otherShowable);
};