
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
	Showable **allShowable;
	int* showableLength;
	std::clock_t lastTime;
public:
	virtual void update(std::clock_t time) = 0;
	virtual void collide(Showable* otherShowable) = 0;
	int getY()
	{
		return y;
	}
	int getX()
	{
		return x;
	}
	Bitmap* getMainImage()
	{
		return mainImage;
	}
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
	Showable(int startX, int startY, Showable **& allShowable, int * showableLength, int width, int height);
	int paint(Showable** backBuffer);
	void present(pixel* frontBuffer, int thisIndex, RECT* allCollisions, int &allCollisionsLength, Showable** backBuffer);
	RECT* getRect()
	{
		RECT* temp = new RECT;
		(*temp).top = y;
		(*temp).left = x;
		(*temp).bottom = y + mainImage->getHeight();
		(*temp).right = x + mainImage->getWidth();
		return temp;
	}
	void addCollision(RECT collisionRECT)
	{
		collisions[collisionCount] = collisionRECT;
		collisionCount++;
	}
	POINT checkRowClean(int y, int collisionIndex)
	{
		POINT tempPoint;
		if (collisions[collisionIndex].bottom >= y && collisions[collisionIndex].top <= y)
		{
			if (collisions[collisionIndex].right >= x + mainImage->getWidth())
			{
				tempPoint.y = x + mainImage->getWidth();
			}
			else
			{
				tempPoint.y = collisions[collisionIndex].right;
			}
			if (collisions[collisionIndex].left <= x)
			{
				tempPoint.x = x;
			}
			else
			{
				tempPoint.x = collisions[collisionIndex].left;
			}
		}
		else
		{
			tempPoint.x = 0;
			tempPoint.y = 0;
		}
	return tempPoint;
}
	bool rectCollide(RECT otherRECT)
	{
		RECT *myRECT = getRect();
		if ((*myRECT).left < otherRECT.right && (*myRECT).right > otherRECT.left &&
			(*myRECT).top < otherRECT.bottom && (*myRECT).bottom > otherRECT.top)
		{
			delete myRECT;
			return true;
		}
		delete myRECT;
		return false;
	}
	void setAllShowable(Showable** newAllShowable)
	{
 		allShowable = newAllShowable;
	}
	Showable()
	{

	}
};

