#pragma once
#include "Main.h"


class Bitmap;
class Showable;

class Actor : public Showable
{
protected:
	int velocityX;
	int velocityY;
	int deltaX;
	int deltaY;
	/* might want these
	int accelerationX;
	int accelerationY;
	*/
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
