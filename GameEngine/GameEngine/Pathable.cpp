#include "Main.h"
void Pathable::update()
{
	if (pathLength > 0)
	{
		double theta = atan((double)path[pathCurrent].y / (double)path[pathCurrent].x);
		velocityX = (int)(velocityTotal*cos(theta));
		velocityY = (int)(velocityTotal*sin(theta));
		if ((!(x+velocityX < path[pathCurrent].x-velocityX) && !(path[pathCurrent].x < x)) && (!(y+velocityY < path[pathCurrent].y-velocityY) && !(path[pathCurrent].y  < y)))
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

Pathable* Pathable::appendPath(POINT * addedPath, int pathCount)
{
	pathLength += pathCount;
	for (int iii = 0; iii < pathCount; iii++)
	{
		path[pathLength + iii] = addedPath[iii];

	}
	pathLength += pathCount;
	return this;
}

Pathable * Pathable::appendPath(POINT addedPath)
{
	path[pathLength] = addedPath;
	pathLength++;
	return this;
}

Pathable::Pathable(int startX, int startY, Bitmap * allSprites, Showable **& allShowable, int & showableLength, int width, int height) : Actor(startX, startY, allSprites, allShowable, showableLength, width, height)
{
	depth = 0;
}
