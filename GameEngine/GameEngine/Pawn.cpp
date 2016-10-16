#include "Main.h"

Pawn::Pawn(int startX, int startY, Bitmap *allSprites, Showable **&allShowable, int &showableLength, int width, int height) : Actor(startX, startY, allSprites, allShowable, showableLength, width, height)
{
	depth = .75;
}

void Pawn::inputReact(char input)
{
	switch (input)
	{
	case 'w':
		velocityY = -10;
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
