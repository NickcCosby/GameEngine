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
		velocityY = 100;
		velocityX = 0;
		break;
	case 's':
		velocityY = -100;
		velocityX = 0;
		break;
	case 'a':
		velocityY = 0;
		velocityX = -100;
		break;
	case 'd':
		velocityY = 0;
		velocityX = 100;
		break;
	}
}
