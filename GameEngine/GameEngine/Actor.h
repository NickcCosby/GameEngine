#pragma once
#include "Main.h"
class Bitmap;

class Actor : public Showable
{
protected:
	int width;
	int height;
	int x;
	int y;
	int velocityX;
	int velocityY;
	/* might want these
	int accelerationX;
	int accelerationY;
	*/
public:
	int paint(Showable ***backBuffer, int screenWidth, int screenHeight);
	COLORREF getColor(int globalX, int globalY);
	void update();
};

#include "Pawn.h"