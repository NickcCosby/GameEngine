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
	Actor(int startX, int startY, Showable **&allShowable, int &showableLength);
	int paint(Showable ***backBuffer, int screenWidth, int screenHeight);
	pixel getColor(int globalX, int globalY);
	void update();
	~Actor()
	{
		delete mainImage;
	}
};

#include "Pawn.h"