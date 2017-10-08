#include "Main.h"

Projectile::Projectile(int startX, int startY, Bitmap * allSprites, Showable **& allShowable, int * showableLength, int width, int height) : Pathable(startX, startY, allSprites, allShowable, showableLength, width, height), Actor(startX, startY, allSprites, allShowable, showableLength, width, height)
{
	velocityTotal = 600;
	animationSetUp(allSprites);

}

void Projectile::collide(Showable * otherShowable)
{
	if (dynamic_cast<EnemyShip*>(otherShowable))
	{
		isDead = true;
	}
}

void Projectile::update(std::clock_t time)
{
	Pathable::update(time);
	if (pathEnded == true)
	{
		isDead = true;
	}
}

void Projectile::animationSetUp(Bitmap * allSprites)
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