#pragma once
#include "Main.h"

class Bitmap;

class Background : Showable
{
private:
	Bitmap *fullImage;
	int x, y;

public:
	inline pixel Background::getColor(int globalX, int globalY)
	{
		return mainImage->getColor(globalX, globalY);
	}
	Background(std::string full, Showable ** allShowable, int &showableLength, int width, int height);
	int paint(Showable ***backBuffer);
	void update();
	~Background()
	{
		delete mainImage;
		delete fullImage;
	}
};