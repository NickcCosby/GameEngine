#pragma once
#include "Main.h"

class Pawn : public Actor
{
public:
	Pawn(int startX, int startY, Bitmap *allSprites, Showable **&allShowable, int &showableLength, int width, int height);
	void inputReact(char input);
	~Pawn()
	{
		delete mainImage;
	}
};
