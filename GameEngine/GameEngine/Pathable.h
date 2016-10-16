#pragma once
#include "Actor.h"

class Pathable : public Actor
{
protected:
	POINT* path;
	int pathCurrent;
	int pathLength;
	int velocityTotal;
	bool loop;
	bool pathEnded;
public:
	Pathable(int startX, int startY, Bitmap *allSprites, Showable **&allShowable, int *showableLength, int width, int height);
	void update();
	Pathable* appendPath(POINT* addedPath, int pathCount);
	Pathable* appendPath(POINT addedPath);
};