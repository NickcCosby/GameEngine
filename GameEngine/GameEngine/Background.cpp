#include "Main.h"

Background::Background(std::string full, int width, int height)
{
	screenWidth = width;
	screenHeight = height;
	mainImage = new Bitmap(full);
}

void Background::present(pixel* frontBuffer, Showable** allShowable, int showableLength, int thisIndex, RECT* allCollisions, int &allCollisionsLength, Showable** backBuffer)
{
	std::memcpy((void*)frontBuffer, (void*)mainImage->getColors(), sizeof(pixel)*screenWidth*screenHeight);
}