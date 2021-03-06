#pragma once
#include "Pawn.h"


class Ship : public Pawn
{
protected:
	Bitmap* bulletImage;
public:
	Ship(int startX, int startY, Bitmap *allSprites, Showable **allShowable, int *showableLength, int width, int height);
	void collide(Showable *otherShowable);
	void inputReact(char input, bool down);
	void addCollisions(RECT collisionRECT)
	{

	}
private:
	void animationSetUp(Bitmap* allSprites);
};
