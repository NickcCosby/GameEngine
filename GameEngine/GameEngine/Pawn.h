#pragma once
#include "Actor.h"


class Pawn : public Actor
{
public:
	Pawn(int startX, int startY, Bitmap *allSprites, Showable **&allShowable, int *showableLength, int width, int height);
	void collide(Showable *otherShowable);
	void inputReact(char input);
	~Pawn()
	{
		delete mainImage;
	}
	void addCollisions(RECT collisionRECT)
	{

	}
};
