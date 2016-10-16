#include "Main.h"

Actor::Actor(int startX, int startY, Bitmap *allSprites, Showable **&allShowable, int *showableLength, int width, int height) : Showable(startX, startY, allShowable, showableLength, width, height)
{
	mainImage = allSprites;
}

void Actor::update()
{
	if (x+velocityX >= 0 && x+velocityX+mainImage->getWidth() < screenWidth)
	{
		x += velocityX;
	}
	else if (x + velocityX + mainImage->getWidth() > screenWidth)
	{
		x = screenWidth - mainImage->getWidth() - 1;
	}
	else if(x + velocityX <= 0)
	{
		x = 1;
	}
	if (y + velocityY >= 0 && y + velocityY + mainImage->getHeight() < screenHeight)
	{
		y += velocityY;
	}
	else if (y + velocityY + mainImage->getHeight() > screenHeight)
	{
		y = screenHeight - mainImage->getHeight() - 1;
	}
	else if (y + velocityY <= 0)
	{
		y = 1;
	}
}
