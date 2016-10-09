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
	void present(pixel* frontBuffer, Showable** allShowable, int showableLength, int thisIndex, RECT* allCollisions, int &allCollisionsLength, Showable** backBuffer);
	int paint(Showable **backBuffer)
	{
		return 0;
	}
	void addCollisions(RECT collisionRECT)
	{
	}
	RECT getRect()
	{
		RECT temp;
		temp.top = 0;
		temp.bottom = 0;
		temp.right = 0;
		temp.left = 0;
		return temp;
	}
	void update();
	~Background()
	{
		delete mainImage;
		delete fullImage;
	}
};