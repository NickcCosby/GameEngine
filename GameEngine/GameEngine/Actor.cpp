#include "Actor.h"

Actor::Actor(int startX, int startY, Showable **& allShowable, int & showableLength, int width, int height) : Showable(allShowable, showableLength, width, height)
{
	x = startX;
	y = startY;
}

int Actor::paint(Showable ** backBuffer)
{
	for (int iii = y; iii < mainImage->getHeight()+y && iii < screenHeight; iii++)
	{
		for (int bbb = x; bbb < mainImage->getWidth()+x && bbb < screenWidth; bbb++)
		{
			if (backBuffer[bbb + (iii*screenWidth)] == NULL)
					backBuffer[bbb + (iii*screenWidth)] = this;
				else
				{
					if (backBuffer[bbb + (iii*screenWidth)]->getDepth() < depth)
						backBuffer[bbb + (iii*screenWidth)] = this;
				}
		}
	}
	return 0;
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
