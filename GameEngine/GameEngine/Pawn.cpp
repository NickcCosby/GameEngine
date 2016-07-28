#include "Pawn.h"

Pawn::Pawn(int startX, int startY, Bitmap *allSprites, Showable **&allShowable, int &showableLength)
{
	x = startX;
	y = startY;
	allShowable[showableLength] = this;
	showableLength++;
	mainImage = allSprites;
}

void Pawn::inputReact(char input)
{
	switch (input)
	{
	case 'w':
		velocityY = -1;
		velocityX = 0;
		break;
	case 's':
		velocityY = 10;
		velocityX = 0;
		break;
	case 'a':
		velocityY = 0;
		velocityX = -10;
		break;
	case 'd':
		velocityY = 0;
		velocityX = 10;
		break;
	}
}
