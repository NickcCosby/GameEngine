#pragma once
#include "Main.h"

class Bitmap
{
private:
	pixel *colors;
	int width;
	int height;
public:
	inline pixel Bitmap::getColor(int x, int y)
	{
		return colors[((width*y)+x)];
	}
	inline pixel* Bitmap::getRowColors(int y)
	{
		return &colors[width*y];
	}
	inline pixel* Bitmap::getColors()
	{
		return colors;
	}
	int getWidth()
	{
		return width;
	}
	int getHeight()
	{
		return height;
	}
	Bitmap(std::string location);
	Bitmap(int width, int height);
	~Bitmap();
	void setPixelColor(pixel tempColor, int x, int y);
	Bitmap* createSubBitmap(RECT space);

};

#include "Showable.h"