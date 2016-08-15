#include "Background.h"

Background::Background()
{

}

int Background::paint(Showable *** backBuffer, int width, int height)
{
	for (int curHeight = y; curHeight <= y + mainImage->getHeight(); curHeight++)
	{
		for (int curWidth = x; curWidth <= x + mainImage->getWidth(); curWidth++)
		{
			
			if (backBuffer[curWidth][curHeight] == NULL)
			{
				backBuffer[curWidth][curHeight] = this;
			}
		}
	}
	return 0;
}
