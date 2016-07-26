#pragma once
#include "Main.h"

class Bitmap
{
private:
	COLORREF **colors;
	int width;
	int height;
public:
	COLORREF getColor(int x, int y);
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
	void setPixelColor(COLORREF tempColor, int x, int y);
};
