#pragma once
#include "Actor.h"


class Pawn : public Actor
{
protected:
	Bitmap* bulletImage;
public:
	Pawn(int startX, int startY, Bitmap *allSprites, Showable **allShowable, int *showableLength, int width, int height);
	void collide(Showable *otherShowable);
	void inputReact(char input, bool down);
	~Pawn()
	{
		delete mainImage;
	}
	void addCollisions(RECT collisionRECT)
	{

	}
};
