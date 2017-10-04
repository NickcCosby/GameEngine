#include "Main.h"

Runner::Runner(int startX, int startY, Bitmap * allSprites, Showable ** allShowable, int * showableLength, int width, int height, Bitmap * collisionMapGiven) : Actor(startX, startY, allSprites, allShowable, showableLength, width, height)
{
	collisionMap = collisionMapGiven;
}

void Runner::fall()
{
	int whiteColor = 765;
	//check for all on bottom row
	for (int iii = x; iii < mainImage->getWidth() + x; iii++)
	{
		//if bottom row is in collision go 1 above
		if (collisionMap->getColor(iii, y).r + collisionMap->getColor(iii, y).g + collisionMap->getColor(iii, y).b != whiteColor)
		{
			do
			{
				y++;
			} while (collisionMap->getColor(iii, y).r + collisionMap->getColor(iii, y).g + collisionMap->getColor(iii, y).b != whiteColor);
			setInAir(false);
			iii = x;
		}
		//if bottom row is not 1 above collision, fall
		else if (collisionMap->getColor(iii, y - 2).r + collisionMap->getColor(iii, y - 2).g + collisionMap->getColor(iii, y - 2).b == whiteColor)
		{
			setInAir(true);
		}
	}
}

void Runner::setInAir(bool inAirGiven)
{
	inAir = inAirGiven;
	if (inAir)
	{
		accelerationY = -500;
		//set x/y moving velocity to diff later
	}
	else
	{
		accelerationY = 0;
		velocityY = 0;
	}
}
