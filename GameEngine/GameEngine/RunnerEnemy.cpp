#include "Main.h"

RunnerEnemy::RunnerEnemy(int startX, int startY, Bitmap *allSprites, Showable **allShowable, int *showableLength, int width, int height, Bitmap* collisionMapGiven) : RunnerPathable(startX, startY, allSprites, allShowable, showableLength, width, height, collisionMapGiven), Actor(startX, startY, allSprites, allShowable, showableLength, width, height)
{
	velocityTotal = 150;
	loop = false;
	depth = .5;
	POINT tempPathPoint;
	tempPathPoint.x = 0;
	tempPathPoint.y = 0;
	appendPath(tempPathPoint);
}

void RunnerEnemy::pathEnd()
{
	x = 1600;
	y = 0;
	POINT tempPathPoint;
	tempPathPoint.x = 0;
	tempPathPoint.y = 0;
	appendPath(tempPathPoint);
}



