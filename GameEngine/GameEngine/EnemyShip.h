#pragma once
#include "Pathable.h"

class Pathable;

class EnemyShip : public Pathable
{
protected:

public:
	EnemyShip(int startX, int startY, Bitmap *allSprites, Showable **allShowable, int *showableLength, int width, int height);
	void collide(Showable* otherShowable);
	void pathEnd()
	{

	}
};