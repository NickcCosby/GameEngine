#pragma once
#include "Showable.h"
#define WALKING_ANIMATION 1

class Bitmap;
class Showable;

class Actor : public Showable
{
private:
	virtual void animationSetUp(Bitmap* allSprites) = 0;
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
};

#include "Pawn.h"
#include "Pathable.h"
