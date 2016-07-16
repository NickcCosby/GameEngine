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
	Bitmap(std::string location);
};
