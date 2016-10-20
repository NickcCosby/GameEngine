#include "Main.h"

Ai::Ai(int startX, int startY, Bitmap * allSprites, Showable **& allShowable, int * showableLength, int width, int height) : Pathable(startX, startY, allSprites, allShowable, showableLength, width, height)
{
	velocityTotal = 5;
	loop = true;
	depth = .5;
	POINT *tempPointArray = new POINT[10];
	for  (int iii = 0; iii < 10; iii++)
	{
		tempPointArray[iii].x = rand() % screenWidth;
		tempPointArray[iii].y = rand() % screenHeight;
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
