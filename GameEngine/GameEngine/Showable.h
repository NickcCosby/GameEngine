#pragma once
#include "Main.h"

class Bitmap;
class Actor;

class Showable
{
protected:
	Bitmap *mainImage;
	double depth;
public:
	virtual int paint(Showable ***backBuffer, int width, int height); //adds pointers onto depthCheck array
	virtual double getDepth()
	{
		return depth;
	}
	virtual COLORREF getColor(int globalX, int globalY);
};
