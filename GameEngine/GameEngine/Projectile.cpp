#include "Main.h"

Projectile::Projectile(int startX, int startY, Bitmap * allSprites, Showable **& allShowable, int * showableLength, int width, int height) : Pathable(startX, startY, allSprites, allShowable, showableLength, width, height)
{
	velocityTotal = 15;
}

void Projectile::collide(Showable * otherShowable)
{
	if (dynamic_cast<Ai*>(otherShowable))
	{
		isDead = true;
	}
}

void Projectile::update()
{
	Pathable::update();
	if (pathEnded == true)
	{
		isDead = true;
	}
}
