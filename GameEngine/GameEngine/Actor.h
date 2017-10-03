#pragma once
#include "Showable.h"


class Bitmap;
class Showable;

class Actor : public Showable
{
protected:
	double velocityX;
	double velocityY;
	int deltaX;
	int deltaY;
	double accelerationX;
	double accelerationY;
public:
	Actor(int startX, int startY, Bitmap *allSprites, Showable **&allShowable, int *showableLength, int width, int height);
	void update(std::clock_t time);
	~Actor()
	{
		delete mainImage;
	}
};

#include "Pawn.h"
#include "Pathable.h"
