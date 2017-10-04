#pragma once
#include "Actor.h"

class Runner : virtual public Actor
{
protected:
	Bitmap* collisionMap;
	bool inAir;

	Runner(int startX, int startY, Bitmap *allSprites, Showable **allShowable, int *showableLength, int width, int height, Bitmap* collisionMapGiven);
	void fall();
	void setInAir(bool inAirGiven);
};
