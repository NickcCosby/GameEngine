#include "Actor.h"

int Actor::paint(Showable *** backBuffer, int screenWidth, int screenHeight)
{
	for (int iii = y; iii < height+y && y+iii < screenHeight; iii++)
	{
		for (int bbb = x; bbb < width+x && x+bbb < screenWidth; bbb++)
		{
			if (mainImage->getColor(bbb, iii) != NULL)
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
	}
	return 0;
}

COLORREF Actor::getColor(int globalX, int globalY)
{
	int bitmapX;
	int bitmapY;
	bitmapX = globalX - x;
	bitmapY = globalY - y;
	return mainImage->getColor(bitmapX, bitmapY);
}
