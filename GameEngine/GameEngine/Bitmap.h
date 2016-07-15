#pragma once
#include "Main.h"

class Bitmap
{
private:
	COLORREF *colors;
public:
	COLORREF getColor(int x, int y);
	Bitmap(int width, int height, std::string location);
};
