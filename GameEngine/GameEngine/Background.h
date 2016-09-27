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
	Background(std::string full, int width, int height);
	void present(pixel * frontBuffer);
	int paint(Showable **backBuffer)
	{
		return 0;
	}
	void update();
	~Background()
	{
		delete mainImage;
		delete fullImage;
	}
};