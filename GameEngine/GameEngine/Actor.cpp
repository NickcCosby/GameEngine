#include "Actor.h"

Actor::Actor(int startX, int startY, Showable **& allShowable, int & showableLength, int width, int height) : Showable(allShowable, showableLength, width, height)
{
	x = startX;
	y = startY;
}

int Actor::paint(Showable ** backBuffer)
{
	for (int iii = y; iii < mainImage->getHeight()+y && iii < screenHeight; iii++)
	{
		for (int bbb = x; bbb < mainImage->getWidth()+x && bbb < screenWidth; bbb++)
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

void Actor::present(pixel* frontBuffer, Showable** allShowable, int showableLength, int thisIndex, RECT* allCollisions, int &allCollisionsLength, Showable** backBuffer)
{
	//find all collisions
	RECT otherRECT, collisionRECT;
	RECT myRECT = getRect();
	{
		for (int vvv = thisIndex+1; vvv < showableLength; vvv++)
		{
			if (rectCollide(allShowable[vvv]->getRect()))
			{
				otherRECT = allShowable[vvv]->getRect();
				if (myRECT.right > otherRECT.left)
				{
					collisionRECT.right = myRECT.right;
					collisionRECT.left = otherRECT.left;
				}
				else
				{
					collisionRECT.right = otherRECT.right;
					collisionRECT.left = myRECT.left;
				}
				if (myRECT.bottom > otherRECT.top)
				{
					collisionRECT.bottom = myRECT.bottom;
					collisionRECT.top = otherRECT.top;
				}
				else
				{
					collisionRECT.bottom = otherRECT.bottom;
					collisionRECT.top = otherRECT.top;
				}
				allCollisions[allCollisionsLength] = collisionRECT;
				collisions[collisionCount] = collisionRECT;
				allCollisionsLength++;
				collisionCount++;
				allShowable[vvv]->addCollisions(collisionRECT);
			}
		}
	}
	//paint non-collision areas onto frontBuffer
	{
		for (int curHeight = y; curHeight < y + mainImage->getHeight(); curHeight++)
		{
			if (checkRowClean(curHeight) == true)
			{
				std::memcpy(&frontBuffer[(screenWidth*(curHeight)) + x], mainImage->getRowColors(curHeight-y), (sizeof(pixel)*mainImage->getWidth()));
			}
		}
	}
	//paint backBuffer where collision is
	{
		for (int iii = 0; iii < collisionCount; iii++)
		{
			for (int yCur = collisions[iii].top; yCur < collisions[iii].bottom; yCur++)
			{
				for (int xCur = collisions[iii].right; xCur < collisions[iii].left; xCur++)
				{
					if (backBuffer[xCur + (yCur*screenWidth)] == NULL)
						backBuffer[xCur + (yCur*screenWidth)] = this;
					else
					{
						if (backBuffer[xCur + (yCur*screenWidth)]->getDepth() < depth)
						{
							backBuffer[xCur + (yCur*screenWidth)] = this;
						}
					}
				}
			}
		}
	}
}


void Actor::update()
{
	if (x+velocityX >= 0 && x+velocityX+mainImage->getWidth() < screenWidth)
	{
		x += velocityX;
	}
	else if (x + velocityX + mainImage->getWidth() > screenWidth)
	{
		x = screenWidth - mainImage->getWidth() - 1;
	}
	else if(x + velocityX <= 0)
	{
		x = 1;
	}
	if (y + velocityY >= 0 && y + velocityY + mainImage->getHeight() < screenHeight)
	{
		y += velocityY;
	}
	else if (y + velocityY + mainImage->getHeight() > screenHeight)
	{
		y = screenHeight - mainImage->getHeight() - 1;
	}
	else if (y + velocityY <= 0)
	{
		y = 1;
	}
}
