#pragma once
#include "Main.h"

class Bitmap;

class Showable
{
protected:
	Bitmap *mainImage;
	double depth;
	bool isDead = 0;
public:
	virtual int paint(Showable ***backBuffer, int width, int height) = 0; //adds pointers onto depthCheck array
	virtual double getDepth()
	{
		return depth;
	}
	virtual bool getIsDead()
	{
		return isDead;
	}
	virtual COLORREF getColor(int globalX, int globalY) = 0;
	virtual void update() = 0;
	~Showable()
	{
		delete mainImage;
	}
};

#include "Actor.h"