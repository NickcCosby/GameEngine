#pragma once
#include "Main.h"

class Pawn : public Actor
{
public:
	Pawn(int startX, int startY, Bitmap *allSprites, Showable **&allShowable, int &showableLength);
	void inputReact(char input);
};
