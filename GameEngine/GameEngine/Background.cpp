#include "Background.h"

Background::Background(std::string full, int width, int height)
{
	screenWidth = width;
	screenHeight = height;
	mainImage = new Bitmap(full);
}

void Background::present(pixel* frontBuffer)
{
	std::memcpy((void*)frontBuffer, (void*)mainImage->getColors(), sizeof(pixel)*screenWidth*screenHeight);
}



void Background::update()
{
}
