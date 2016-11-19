#include "Main.h"

Pawn::Pawn(int startX, int startY, Bitmap *allSprites, Showable **allShowable, int *showableLength, int width, int height) : Actor(startX, startY, allSprites, allShowable, showableLength, width, height)
{
	depth = .75;
	bulletImage = new Bitmap("Bullet.bmp");
}

void Pawn::collide(Showable * otherShowable)
{
}

void Pawn::inputReact(char input, bool down)
{
	if (down)
	{
		switch (input)
		{
		case 'w':
			velocityY = 500;
			velocityX = 0;
			break;
		case 's':
			velocityY = -500;
			velocityX = 0;
			break;
		case 'a':
			velocityY = 0;
			velocityX = -500;
			break;
		case 'd':
			velocityY = 0;
			velocityX = 500;
			break;
		case ' ':
			Projectile* bullet;
			bullet = new Projectile(x + (mainImage->getWidth() / 2), y, bulletImage, allShowable, showableLength, screenWidth, screenHeight);
			POINT tempPoint;
			tempPoint.x = x + (mainImage->getWidth() / 2);
			tempPoint.y = screenHeight - bulletImage->getHeight();
			bullet->appendPath(tempPoint);
			break;
		case 'r':
			Bitmap* enemySprite = new Bitmap("RealEnemyShip.bmp");
			Ai *enemy = new Ai(screenWidth / 2, screenHeight / 4, enemySprite, allShowable, showableLength, screenWidth, screenHeight);
			break;
		}
	}
	else
	{
		switch (input)
		{
		case 'w':
			velocityY = 0;
			break;
		case 's':
			velocityY = 0;
			break;
		case 'a':
			velocityX = 0;
			break;
		case 'd':
			velocityX = 0;
			break;
		}
	}
}
