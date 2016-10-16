#include "Main.h"

Ai::Ai(int startX, int startY, Bitmap * allSprites, Showable **& allShowable, int * showableLength, int width, int height) : Pathable(startX, startY, allSprites, allShowable, showableLength, width, height)
{
	velocityTotal = 5;
	loop = true;
	depth = .5;
}

void Ai::collide(Showable * otherShowable)
{
	if (dynamic_cast<Projectile*>(otherShowable))
	{
		isDead = true;
	}
}
