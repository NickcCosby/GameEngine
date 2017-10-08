#include "Main.h"

EnemyShip::EnemyShip(int startX, int startY, Bitmap * allSprites, Showable ** allShowable, int * showableLength, int width, int height) : Pathable(startX, startY, allSprites, allShowable, showableLength, width, height), Actor(startX, startY, allSprites, allShowable, showableLength, width, height)
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
	animationSetUp(allSprites);

}

void EnemyShip::collide(Showable * otherShowable)
{
	if (dynamic_cast<Projectile*>(otherShowable))
	{
		isDead = true;
	}
}

void EnemyShip::animationSetUp(Bitmap * allSprites)
{
	animationTracks = new Bitmap**[1];
	animationTracks[0] = new Bitmap*[1];
	animationTracks[0][0] = allSprites;
	animationLength = new int[1];
	animationLength[0] = 1;
	frameLength = new int*[1];
	frameLength[0] = new int[1];
	frameLength[0][0] = 100;
	activeAnimation = IDLE_ANIMATION;
	activeFrame = 0;
	animationEnd = new animationEndType[1];
	animationEnd[0] = &Showable::animationEndLoop;
}