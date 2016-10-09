#pragma once
#include "Main.h"

class Bitmap;

class Showable
{
protected:
	Bitmap *mainImage;
	double depth;
	bool isDead = 0;
	int screenWidth;
	int screenHeight;
	RECT* collisions;
	int collisionCount;
public:
	virtual int paint(Showable **backBuffer) = 0; //adds pointers onto depthCheck array
	virtual double getDepth()
	{
		return depth;
	}
	virtual bool getIsDead()
	{
		return isDead;
	}
	virtual pixel getColor(int globalX, int globalY) = 0;
	virtual void update() = 0;
	~Showable()
	{
		delete mainImage;
	}
	virtual void present(pixel* frontBuffer, Showable** allShowable, int showableLength, int thisIndex, RECT* allCollisions, int &allCollisionsLength, Showable** backBuffer) = 0;
	Showable(Showable ** allShowable, int &showableLength, int width, int height);
	virtual RECT getRect() = 0;
	virtual void addCollisions(RECT collisionRECT) = 0;
	Showable()
	{

	}
};

#include "Actor.h"
#include "Background.h"