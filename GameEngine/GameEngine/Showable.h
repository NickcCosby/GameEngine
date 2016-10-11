
#pragma once
#include "Bitmap.h"

class Bitmap;

class Showable
{
protected:
	int x;
	int y;
	Bitmap *mainImage;
	double depth;
	bool isDead = 0;
	int screenWidth;
	int screenHeight;
	RECT* collisions;
	int collisionCount;
public:
	virtual void update() = 0;
	double getDepth()
	{
		return depth;
	}
	bool getIsDead()
	{
		return isDead;
	}
	inline pixel getColor(int globalX, int globalY)
	{
		int bitmapX = globalX - x;
		int bitmapY = globalY - y;
		return mainImage->getColor(bitmapX, bitmapY);
	}
	Showable(int startX, int startY, Showable **& allShowable, int & showableLength, int width, int height);
	int paint(Showable** backBuffer);
	void present(pixel* frontBuffer, Showable** allShowable, int showableLength, int thisIndex, RECT* allCollisions, int &allCollisionsLength, Showable** backBuffer);
	RECT getRect()
	{
		RECT temp;
		temp.top = y;
		temp.left = x;
		temp.bottom = y + mainImage->getHeight();
		temp.right = x + mainImage->getWidth();
		return temp;
	}
	void addCollision(RECT collisionRECT)
	{
		collisions[collisionCount] = collisionRECT;
		collisionCount++;
	}
	bool checkRowClean(int y)
	{
		for (int nnn = 0; nnn < collisionCount; nnn++)
		{
			if (collisions[nnn].bottom > y && collisions[nnn].top < y)
			{
				if (collisions[nnn].right > x + mainImage->getWidth() && collisions[nnn].left < x)
				{
					return false;
				}
				else
				{
					return true;
				}
			}
		}
		return true;
	}
	bool rectCollide(RECT otherRECT)
	{
		RECT myRECT = getRect();
		if (myRECT.left < otherRECT.right && myRECT.right > otherRECT.left &&
			myRECT.top < otherRECT.bottom && myRECT.bottom > otherRECT.top)
		{
			return true;
		}
		return false;
	}
	Showable()
	{

	}
};

