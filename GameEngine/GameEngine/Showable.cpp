#include "Showable.h"

Showable::Showable(Showable ** allShowable, int &showableLength, int width, int height)
{
	allShowable[showableLength] = this;
	showableLength++;
	screenWidth = width;
	screenHeight = height;
	collisions = new RECT[100];
	collisionCount = 0;
}
