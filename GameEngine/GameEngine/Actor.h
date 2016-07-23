#pragma once
#include "Main.h"

class Showable;
class Bitmap;

class Actor : public Showable
{
private:
	int width;
	int height;
	double x;
	double y;
public:
	int paint(Showable ***backBuffer, int screenWidth, int screenHeight);
	COLORREF getColor(int globalX, int globalY);
};
