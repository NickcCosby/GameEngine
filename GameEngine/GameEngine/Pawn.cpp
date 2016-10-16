#include "Main.h"

Pawn::Pawn(int startX, int startY, Bitmap *allSprites, Showable **&allShowable, int *showableLength, int width, int height) : Actor(startX, startY, allSprites, allShowable, showableLength, width, height)
{
	depth = .75;
}

void Pawn::collide(Showable * otherShowable)
{
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
	case ' ':
		Projectile* bullet;
		bullet = new Projectile(x, y, mainImage, allShowable, showableLength, screenWidth, screenHeight);
		POINT tempPoint;
		tempPoint.x = x;
		tempPoint.y = 0;
		bullet->appendPath(tempPoint);
		break;
	case 'r':
		Bitmap* enemySprite = new Bitmap("enemy.bmp");
		Ai *enemy = new Ai(screenWidth / 2, screenHeight / 4, enemySprite, allShowable, showableLength, screenWidth, screenHeight);
		break;
	}
}
