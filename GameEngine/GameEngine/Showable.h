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
public:
	virtual int paint(Showable ***backBuffer) = 0; //adds pointers onto depthCheck array
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
	Showable(Showable ** allShowable, int &showableLength, int width, int height);
};

#include "Actor.h"
#include "Background.h"