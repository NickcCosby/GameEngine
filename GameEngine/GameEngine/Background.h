#pragma once
#include "Bitmap.h"
class Bitmap;

class Background
{
private:
	Bitmap *fullImage;
	int x, y;
	Bitmap *mainImage;
	int screenWidth;
	int screenHeight;
public:
	Background(std::string full, int width, int height);
	void present(pixel* frontBuffer, Showable** allShowable, int showableLength, int thisIndex, RECT* allCollisions, int &allCollisionsLength, Showable** backBuffer);
	inline Bitmap* getMainImage()
	{
		return mainImage;
	}
};