#pragma once
#include "Main.h"

class Background : Showable
{
private:
	Bitmap *fullImage;
	int x, y;
public:
	Background(std::string full);
	virtual int paint(Showable ***backBuffer, int width, int height);
	virtual pixel getColor(int globalX, int globalY);
	virtual void update();
	~Background()
	{
		delete mainImage;
		delete fullImage;
	}
};