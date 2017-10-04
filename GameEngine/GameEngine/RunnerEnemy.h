#pragma once
#include "RunnerPathable.h"

class RunnerEnemy : public RunnerPathable
{
public:
	RunnerEnemy(int startX, int startY, Bitmap *allSprites, Showable **allShowable, int *showableLength, int width, int height, Bitmap* collisionMapGiven);
private:
	void pathEnd();
	void collide(Showable* otherShowable)
	{ 

	}
protected:

};