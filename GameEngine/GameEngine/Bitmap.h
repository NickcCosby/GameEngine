#pragma once
#include "Main.h"

class Bitmap
{
private:
	pixel **colors;
	int width;
	int height;
public:
	pixel getColor(int x, int y);
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
};
