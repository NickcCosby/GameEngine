#pragma once
#include "Pawn.h"

class RunnerPawn : public Pawn
{
protected:
	Bitmap *collisionMap;
	bool inAir;
public:
	RunnerPawn(int startX, int startY, Bitmap *allSprites, Showable **allShowable, int *showableLength, int width, int height, Bitmap* collisionMapGiven);
	void collide(Showable *otherShowable);
	void inputReact(char input, bool down);
	void update(std::clock_t time);
	~RunnerPawn()
	{
		delete mainImage;
	}
	void addCollisions(RECT collisionRECT)
	{

	}
	void setInAir(bool inAirGiven);
};
