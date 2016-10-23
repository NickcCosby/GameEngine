#pragma once
#include "Showable.h"
#include "Pathable.h"

class Showable;
class Pathable;
class Bitmap;

class Projectile : public Pathable
{
protected:

public:
	Projectile(int startX, int startY, Bitmap *allSprites, Showable **&allShowable, int *showableLength, int width, int height);
	void collide(Showable* otherShowable);
	void update(std::clock_t time);
};