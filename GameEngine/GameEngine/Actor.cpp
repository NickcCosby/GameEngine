#include "Main.h"

Actor::Actor(int startX, int startY, Bitmap *allSprites, Showable **&allShowable, int *showableLength, int width, int height) : Showable(startX, startY, allShowable, showableLength, width, height)
{
	mainImage = allSprites;
	lastTime = 0;
	deltaX = 0;
	deltaY = 0;
	velocityX = 0;
	velocityY = 0;
}

void Actor::update(std::clock_t time)
{
	if (lastTime != 0)
	{
		double deltaVelocityX;
		double deltaVelocityY;
		double duration = (time - lastTime) / (double)CLOCKS_PER_SEC;
		deltaVelocityX = (accelerationX * duration);
		deltaVelocityY = (accelerationY * duration);
		velocityX += deltaVelocityX;
		velocityY += deltaVelocityY;
		deltaX = (int)round(velocityX * duration);
		deltaY = (int)round(velocityY * duration);

		if (x + deltaX >= 0 && x + deltaX + mainImage->getWidth() < screenWidth)
		{
			x += deltaX;
		}
		else if (x + deltaX + mainImage->getWidth() > screenWidth)
		{
			x = screenWidth - mainImage->getWidth() - 1;
		}
		else if (x + deltaX <= 0)
		{
			x = 1;
		}
		if (y + deltaY >= 0 && y + deltaY + mainImage->getHeight() < screenHeight)
		{
			y += deltaY;
		}
		else if (y + deltaY + mainImage->getHeight() > screenHeight)
		{
			y = screenHeight - mainImage->getHeight() - 1;
		}
		else if (y + deltaY <= 0)
		{
			y = 1;
		}
	}
	lastTime = time;
}
