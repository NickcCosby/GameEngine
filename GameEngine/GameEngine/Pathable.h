#pragma once
#include "Actor.h"

class Pathable : Actor
{
protected:
	POINT* path;
	int pathCurrent;
	int pathLength;
	int velocityTotal = 15;
	bool loop;
public:
	Pathable(int startX, int startY, Bitmap *allSprites, Showable **&allShowable, int &showableLength, int width, int height);
	void update();
	Pathable* appendPath(POINT* addedPath, int pathCount);
	Pathable* appendPath(POINT addedPath);
};