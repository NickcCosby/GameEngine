#pragma once
#include "Actor.h"


class Wire : Actor
{
private:
	Bitmap ** wirePositions;
	int wireIndex;
public:
	Wire(int startX, int startY, Bitmap *allSprites, Showable **&allShowable, int *showableLength, int width, int height, int wireIndex);
};
