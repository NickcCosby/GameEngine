#include "Main.h"

RunnerEnemy::RunnerEnemy(int startX, int startY, Bitmap *allSprites, Showable **allShowable, int *showableLength, int width, int height, Bitmap* collisionMapGiven) : RunnerPathable(startX, startY, allSprites, allShowable, showableLength, width, height, collisionMapGiven), Actor(startX, startY, allSprites, allShowable, showableLength, width, height)
{
	velocityTotal = 150;
	loop = false;
	depth = .5;
	POINT tempPathPoint;
	tempPathPoint.x = 0;
	tempPathPoint.y = 0;
	appendPath(tempPathPoint);
	animationSetUp(allSprites);

}

void RunnerEnemy::pathEnd()
{
	RunnerEnemy* replacement;
	replacement = new RunnerEnemy(1600, 0, mainImage, allShowable, showableLength, screenWidth, screenHeight, collisionMap);
	isDead = true;
}


void RunnerEnemy::animationSetUp(Bitmap * allSprites)
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
	mainImage = animationTracks[IDLE_ANIMATION][0];
}
