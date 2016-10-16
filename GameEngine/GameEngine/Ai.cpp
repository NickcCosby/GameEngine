#include "Main.h"

Ai::Ai(int startX, int startY, Bitmap * allSprites, Showable **& allShowable, int * showableLength, int width, int height) : Pathable(startX, startY, allSprites, allShowable, showableLength, width, height)
{
	velocityTotal = 5;
	loop = true;
	depth = .5;
	POINT *tempPoint, *tempPoint2;
	tempPoint = new POINT;
	tempPoint2 = new POINT;
	POINT *tempPointArray = new POINT[2];
	(*tempPoint).x = width / 4;
	(*tempPoint).y = height / 4;
	(*tempPoint2).x = (width / 4) * 3;
	(*tempPoint2).y = height / 4;
	tempPointArray[0] = *tempPoint;
	tempPointArray[1] = *tempPoint2;
	appendPath(tempPointArray, 2);
}

void Ai::collide(Showable * otherShowable)
{
	if (dynamic_cast<Projectile*>(otherShowable))
	{
		isDead = true;
	}
}
