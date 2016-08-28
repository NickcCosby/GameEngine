#include "Background.h"

Background::Background(std::string full, Showable ** allShowable, int &showableLength) : Showable(allShowable, showableLength)
{
	mainImage = new Bitmap(full);
}

int Background::paint(Showable *** backBuffer, int width, int height)
{
	for (int curHeight = y; curHeight < y + mainImage->getHeight(); curHeight++)
	{
		for (int curWidth = x; curWidth < x + mainImage->getWidth(); curWidth++)
		{
			
			if (backBuffer[curWidth][curHeight] == NULL)
			{
				backBuffer[curWidth][curHeight] = this;
			}
		}
	}
	return 0;
}

pixel Background::getColor(int globalX, int globalY)
{
	return mainImage->getColor(globalX, globalY);
}

void Background::update()
{
}
