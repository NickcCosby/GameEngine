#pragma once
#include "Main.h"
class Bitmap;

class Actor : public Showable
{
protected:
	int x;
	int y;
	int velocityX;
	int velocityY;
	/* might want these
	int accelerationX;
	int accelerationY;
	*/
public:
	inline pixel Actor::getColor(int globalX, int globalY)
	{
		int bitmapX = globalX - x;
		int bitmapY = globalY - y;
		return mainImage->getColor(bitmapX, bitmapY);
	}
	Actor(int startX, int startY, Showable **&allShowable, int &showableLength, int width, int height);
	int paint(Showable** backBuffer);
	void present(pixel* frontBuffer)
	{

	}
	void update();
	~Actor()
	{
		delete mainImage;
	}
};

#include "Pawn.h"