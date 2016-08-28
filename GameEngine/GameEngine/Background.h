#pragma once
#include "Main.h"

class Background : Showable
{
private:
	Bitmap *fullImage;
	int x, y;
public:
	Background(std::string full, Showable ** allShowable, int &showableLength);
	int paint(Showable ***backBuffer, int width, int height);
	pixel getColor(int globalX, int globalY);
	void update();
	~Background()
	{
		delete mainImage;
		delete fullImage;
	}
};