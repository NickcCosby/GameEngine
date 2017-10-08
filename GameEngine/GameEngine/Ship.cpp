#include "Main.h"

Ship::Ship(int startX, int startY, Bitmap *allSprites, Showable **allShowable, int *showableLength, int width, int height) : Pawn(startX, startY, allSprites, allShowable, showableLength, width, height), Actor(startX, startY, allSprites, allShowable, showableLength, width, height)
{
	depth = .75;
	bulletImage = new Bitmap("Bullet.bmp");
	animationSetUp(allSprites);

}

void Ship::collide(Showable * otherShowable)
{
}

void Ship::inputReact(char input, bool down)
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
			EnemyShip *enemy = new EnemyShip(screenWidth / 2, screenHeight / 4, enemySprite, allShowable, showableLength, screenWidth, screenHeight);
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

void Ship::animationSetUp(Bitmap * allSprites)
{
	animationTracks = new Bitmap**[1];
	animationTracks[0] = new Bitmap*[1];
	animationTracks[0][0] = allSprites;
	animationLength = new int[1];
	animationLength[0] = 1;
	frameLength = new int*[1];
	frameLength[0] = new int[1];
	frameLength[0][0] = 100;
	activeAnimation = IDLE_ANIMATION;
	activeFrame = 0;
	animationEnd = new animationEndType[1];
	animationEnd[0] = &Showable::animationEndLoop;
}
