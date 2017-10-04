#include "Main.h"

RunnerPathable::RunnerPathable(int startX, int startY, Bitmap * allSprites, Showable ** allShowable, int * showableLength, int width, int height, Bitmap * collisionMapGiven) : Pathable(startX, startY, allSprites, allShowable, showableLength, width, height), Runner(startX, startY, allSprites, allShowable, showableLength, width, height, collisionMapGiven), Actor(startX, startY, allSprites, allShowable, showableLength, width, height)
{

}

void RunnerPathable::update(std::clock_t time)
{
	fall();
	if (pathLength > 0)
	{
		double xDiff = path[pathCurrent].x - x;
		if (xDiff >= 0)
		{
			velocityX = velocityTotal;
		}
		else
		{
			velocityX = -1 * velocityTotal;
		}
		Actor::update(time);
		if (abs(xDiff) <= abs(deltaX))
		{
			if (pathCurrent + 1 == pathLength)
			{
				if (loop)
				{
					pathCurrent = 0;
				}
				else
				{
					pathEnded = true;
					delete[] path;
					path = new POINT[100];
					pathCurrent = 0;
					pathLength = 0;
					pathEnd();
				}
			}
			else
			{
				pathCurrent++;
			}
		}
	}
	else
	{
		velocityX = 0;
		Actor::update(time);
	}
}
