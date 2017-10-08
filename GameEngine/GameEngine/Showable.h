
#pragma once
#include "Bitmap.h"
#define IDLE_ANIMATION 0


class Bitmap;
class Showable;
typedef void(Showable::*animationEndType)();



class Showable
{
protected:
	int x;
	int y;
	Bitmap *mainImage;
	double depth;
	Bitmap ***animationTracks;
	int *animationLength;
	int **frameLength;
	int activeAnimation;
	int activeFrame;
	bool isDead = 0;
	int screenWidth;
	int screenHeight;
	RECT* collisions;
	int collisionCount;
	Showable **allShowable;
	int* showableLength;
	std::clock_t lastTime;
	std::clock_t lastFrameChange;
	//void (Showable::**animationEnd)();
	animationEndType *animationEnd;

public:
	virtual void clicked(int x, int y, bool left);
	virtual void update(std::clock_t time);
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
	void scaleSprite(float scalePercentage);
	Showable()
	{

	}
	virtual ~Showable()
	{

	}
	void animationEndLoop()
	{
		activeFrame = 0;
	}
	void changeAnimation(int animation);
};

