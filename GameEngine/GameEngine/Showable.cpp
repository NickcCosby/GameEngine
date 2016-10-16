#include "Main.h"

Showable::Showable(int startX, int startY, Showable **& allShowableGiven, int * showableLengthGiven, int width, int height)
{
	allShowable = allShowableGiven;
	showableLength = showableLengthGiven;
	allShowable[*showableLength] = this;
	(*showableLength)++;
	screenWidth = width;
	screenHeight = height;
	collisions = new RECT[100];
	collisionCount = 0;
	x = startX;
	y = startY;
}

int Showable::paint(Showable ** backBuffer)
{
	for (int iii = y; iii < mainImage->getHeight() + y && iii < screenHeight; iii++)
	{
		for (int bbb = x; bbb < mainImage->getWidth() + x && bbb < screenWidth; bbb++)
		{
			if (backBuffer[bbb + (iii*screenWidth)] == NULL)
				backBuffer[bbb + (iii*screenWidth)] = this;
			else
			{
				if (backBuffer[bbb + (iii*screenWidth)]->getDepth() < depth)
				{
					backBuffer[bbb + (iii*screenWidth)] = this;
				}
			}
		}
	}
	return 0;
}

void Showable::present(pixel* frontBuffer, int thisIndex, RECT* allCollisions, int &allCollisionsLength, Showable** backBuffer)
{
	//find all collisions
	RECT* otherRECT, *collisionRECT;
	collisionRECT = new RECT;
	RECT *myRECT = getRect();
	{
		for (int vvv = thisIndex + 1; vvv < *showableLength; vvv++)
		{
			if (rectCollide(*(allShowable[vvv]->getRect())))
			{
				otherRECT = allShowable[vvv]->getRect();
				POINT collisionPoint[4];
				int collisionPointCount = 0;
				if ((*myRECT).top > (*otherRECT).top)
				{
					(*collisionRECT).top = (*myRECT).top;
				}
				else
				{
					(*collisionRECT).top = (*otherRECT).top;
				}
				if ((*otherRECT).bottom < (*myRECT).bottom)
				{
					(*collisionRECT).bottom = (*otherRECT).bottom;
				}
				else
				{
					(*collisionRECT).bottom = (*myRECT).bottom;
				}
				if ((*myRECT).right < (*otherRECT).right)
				{
					(*collisionRECT).right = (*myRECT).right;
				}
				else
				{
					(*collisionRECT).right = (*otherRECT).right;
				}
				if ((*myRECT).left < (*otherRECT).left)
				{
					(*collisionRECT).left = (*otherRECT).left;
				}
				else
				{
					(*collisionRECT).left = (*myRECT).left;
				}
				allCollisions[allCollisionsLength] = (*collisionRECT);
				collisions[collisionCount] = (*collisionRECT);
				allCollisionsLength++;
				collisionCount++;
				allShowable[vvv]->addCollision((*collisionRECT));
				delete myRECT;
				delete otherRECT;
			}
		}
	}
	//paint non-collision areas onto frontBuffer
	{
		for (int curHeight = y; curHeight < y + mainImage->getHeight(); curHeight++)
		{
			std::memcpy(&frontBuffer[(screenWidth*(curHeight)) + x], mainImage->getRowColors(curHeight - y), (sizeof(pixel)*mainImage->getWidth()));
		}
	}
	//paint backBuffer where collision is
	{
		for (int iii = 0; iii < collisionCount; iii++)
		{
			for (int yCur = collisions[iii].top; yCur < collisions[iii].bottom; yCur++)
			{
				for (int xCur = collisions[iii].left; xCur < collisions[iii].right; xCur++)
				{
					if (backBuffer[xCur + (yCur*screenWidth)] == NULL)
						backBuffer[xCur + (yCur*screenWidth)] = this;
					else
					{
						collide(backBuffer[xCur + (yCur*screenWidth)]);
						backBuffer[xCur + (yCur*screenWidth)]->collide(this);
						if (backBuffer[xCur + (yCur*screenWidth)]->getDepth() < depth)
						{
							backBuffer[xCur + (yCur*screenWidth)] = this;
						}
					}
				}
			}
		}
	}
	delete[] collisions;
	collisions = new RECT[100];
	collisionCount = 0;
}

#include "Actor.h"
