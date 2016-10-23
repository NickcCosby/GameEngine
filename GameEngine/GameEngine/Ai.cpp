#include "Main.h"

Ai::Ai(int startX, int startY, Bitmap * allSprites, Showable **& allShowable, int * showableLength, int width, int height) : Pathable(startX, startY, allSprites, allShowable, showableLength, width, height)
{
	velocityTotal = 500;
	loop = true;
	depth = .5;
	POINT *tempPointArray = new POINT[10];
	for  (int iii = 0; iii < 10; iii++)
	{
		tempPointArray[iii].x = abs(rand() % screenWidth-mainImage->getWidth());
		tempPointArray[iii].y = abs(rand() % screenHeight-mainImage->getHeight());
	}
	appendPath(tempPointArray, 10);
}

void Ai::collide(Showable * otherShowable)
{
	if (dynamic_cast<Projectile*>(otherShowable))
	{
		isDead = true;
	}
}
