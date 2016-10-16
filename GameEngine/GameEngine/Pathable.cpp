#include "Main.h"
void Pathable::update()
{
	if (pathLength > 0)
	{
		int absVelocityX;
		int absVelocityY;
		double xDiff = path[pathCurrent].x - x;
		double yDiff = path[pathCurrent].y - y;
		double theta = atan(yDiff / xDiff);
		absVelocityX = (int)(velocityTotal*cos(theta));
		absVelocityY = (int)(velocityTotal*sin(theta));
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
		if (abs(xDiff) <= abs(velocityX) && abs(yDiff) <= abs(velocityY))
		{
			if (pathCurrent + 1 == pathLength)
			{
				if (loop)
				{
					pathCurrent = 0;
				}
				else
				{
					delete[] path;
					path = new POINT[100];
					pathCurrent = 0;
					pathLength = 0;
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
	}
	Actor::update();
}

Pathable* Pathable::appendPaths(POINT * addedPath, int pathCount)
{
	for (int iii = 0; iii < pathCount; iii++)
	{
		path[pathLength + iii] = addedPath[iii];

	}
	pathLength += pathCount;
	return this;
}

Pathable * Pathable::appendPath(POINT * addedPath)
{
	path[pathLength] = *addedPath;
	pathLength++;
	return this;
}

Pathable::Pathable(int startX, int startY, Bitmap * allSprites, Showable **& allShowable, int & showableLength, int width, int height) : Actor(startX, startY, allSprites, allShowable, showableLength, width, height)
{
	path = new POINT[100];
	velocityTotal = 5;
	loop = true;
	depth = .5;
}
