#include "Main.h"
void Pathable::update(std::clock_t time)
{
	if (pathLength > 0)
	{
		int absVelocityX;
		int absVelocityY;
		double xDiff = path[pathCurrent].x - x;
		double yDiff = path[pathCurrent].y - y;
		double theta = atan(yDiff / xDiff);
		absVelocityX = abs((int)(velocityTotal*cos(theta)));
		absVelocityY = abs((int)(velocityTotal*sin(theta)));
		if (xDiff >= 0)
		{
			velocityX = absVelocityX;
		}
		else
		{
			velocityX = -1 * absVelocityX;
		}
		if (yDiff >= 0)
		{
			velocityY = absVelocityY;
		}
		else
		{
			velocityY = -1 * absVelocityY;
		}
		Actor::update(time);
		if (abs(xDiff) <= abs(deltaX) && abs(yDiff) <= abs(deltaY))
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
		velocityY = 0;
		Actor::update(time);
	}
}

Pathable* Pathable::appendPath(POINT * addedPath, int pathCount)
{
	for (int iii = 0; iii < pathCount; iii++)
	{
		path[pathLength + iii] = addedPath[iii];

	}
	pathLength += pathCount;
	return this;
}

Pathable * Pathable::appendPath(POINT  addedPath)
{
	path[pathLength] = addedPath;
	pathLength++;
	return this;
}

Pathable::Pathable(int startX, int startY, Bitmap * allSprites, Showable **& allShowable, int * showableLength, int width, int height) : Actor(startX, startY, allSprites, allShowable, showableLength, width, height)
{
	path = new POINT[100];
	pathEnded = false;
}
