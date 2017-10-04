#pragma once
#include "Pathable.h"


class RunnerPathable : public Pathable, public Runner
{
protected:
	RunnerPathable(int startX, int startY, Bitmap *allSprites, Showable **allShowable, int *showableLength, int width, int height, Bitmap* collisionMapGiven);
private:
	void update(std::clock_t time);
};