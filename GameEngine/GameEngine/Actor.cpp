#include "Actor.h"

Actor::Actor(int startX, int startY, Showable **& allShowable, int & showableLength) : Showable(allShowable, showableLength)
{
	x = startX;
	y = startY;
}

int Actor::paint(Showable *** backBuffer, int screenWidth, int screenHeight)
{
	for (int iii = y; iii < mainImage->getHeight()+y && iii < screenHeight; iii++)
	{
		for (int bbb = x; bbb < mainImage->getWidth()+x && bbb < screenWidth; bbb++)
		{
			if (backBuffer[bbb][iii] == NULL)
					backBuffer[bbb][iii] = this;
				else
				{
					if (backBuffer[bbb][iii]->getDepth() < depth)
						backBuffer[bbb][iii] = this;
				}
		}
	}
	return 0;
}

pixel Actor::getColor(int globalX, int globalY)
{
	int bitmapX;
	int bitmapY;
	bitmapX = globalX - x;
	bitmapY = globalY - y;
	return mainImage->getColor(bitmapX, bitmapY);
}

void Actor::update()
{
	x += velocityX;
	y += velocityY;
}
