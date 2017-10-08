#pragma once
#include "Pawn.h"

class RunnerPawn : public Pawn, public Runner
{
private:
	void animationSetUp(Bitmap* allSprites);
protected:
	
public:
	RunnerPawn(int startX, int startY, Bitmap *allSprites, Showable **allShowable, int *showableLength, int width, int height, Bitmap* collisionMapGiven);
	void collide(Showable *otherShowable);
	void inputReact(char input, bool down);
	void update(std::clock_t time);
	void addCollisions(RECT collisionRECT)
	{

	}
};
