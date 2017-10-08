#include "Main.h"
#define SHIFTED 0x8000

void RunnerPawn::animationSetUp(Bitmap * allSprites)
{
	const int animationCount = 2;
	const int constAnimationLength[2] = { 1, 2 };
	RECT tempRect;
	//defining animationTracks
	{
		animationTracks = new Bitmap**[animationCount];
		animationTracks[0] = new Bitmap*[constAnimationLength[0]];
		animationTracks[1] = new Bitmap*[constAnimationLength[1]];
		tempRect.bottom = 0;
		tempRect.top = 88;
		tempRect.right = 88;
		tempRect.left = 0;
		animationTracks[0][0] = allSprites->createSubBitmap(tempRect);
		animationTracks[1][0] = animationTracks[0][0];
		tempRect.right = 88*2;
		tempRect.left = 88;
		animationTracks[1][1] = allSprites->createSubBitmap(tempRect);
	}
	animationLength = new int[animationCount];
	animationLength[0] = constAnimationLength[0];
	animationLength[1] = constAnimationLength[1];
	//defining frameLength
	{
		frameLength = new int*[animationCount];
		frameLength[0] = new int[constAnimationLength[0]];
		frameLength[1] = new int[constAnimationLength[1]];
		frameLength[0][0] = 100;
		frameLength[1][0] = 300;
		frameLength[1][1] = 300;
	}
	activeAnimation = IDLE_ANIMATION;
	activeFrame = 0;
	animationEnd = new animationEndType[animationCount];
	animationEnd[0] = &Showable::animationEndLoop;
	animationEnd[1] = &Showable::animationEndLoop;
	mainImage = animationTracks[IDLE_ANIMATION][0];
}

RunnerPawn::RunnerPawn(int startX, int startY, Bitmap * allSprites, Showable ** allShowable, int * showableLength, int width, int height, Bitmap * collisionMapGiven) : Pawn(startX, startY, allSprites, allShowable, showableLength, width, height), Runner(startX, startY, allSprites, allShowable, showableLength, width, height, collisionMapGiven), Actor(startX, startY, allSprites, allShowable, showableLength, width, height)
{
	depth = .75;
	animationSetUp(allSprites);

}

void RunnerPawn::collide(Showable *otherShowable)
{

}

void RunnerPawn::inputReact(char input, bool down)
{
	switch (input)
	{
	case 'a':
		buttons.a = true;
		break;
	case 's':
		buttons.s = true;
		break;
	case'd':
		buttons.d = true;
		break;
	case 'w':
		buttons.w = true;
		break;
	case ' ':
		buttons.space = true;
		break;
	}
}



void RunnerPawn::update(std::clock_t time)
{
	fall();
	//movement
	{
		if (buttons.a == true)
		{
			if (lastPressedButtons.a == 0)
			{
				lastPressedButtons.a = time;
			}
			velocityX = (int)-(1 / (2 * (-(time - lastPressedButtons.d) / (double)CLOCKS_PER_SEC) + .02)) - 200;
		}
		if (buttons.a == false && lastPressedButtons.a != 0)
		{
			lastPressedButtons.a = 0;
			velocityX = 0;
		}
		if (buttons.d == true)
		{
			if (lastPressedButtons.d == 0)
			{
				lastPressedButtons.d = time;
			}
			accelerationX = 0;
			velocityX = (int)(1 / (2 * ((time - lastPressedButtons.d) / (double)CLOCKS_PER_SEC) + .02)) + 200;
		}
		if (buttons.d == false && lastPressedButtons.d != 0)
		{
			lastPressedButtons.d = 0;
			velocityX = 0;
		}
		if (buttons.space == true)
		{
			if (lastPressedButtons.space == 0)
			{
				lastPressedButtons.space = time;
				if (!inAir)
				{
					setInAir(true);
					velocityY = 300;
				}
			}
		}
		if (buttons.space == false)
		{
			lastPressedButtons.space = 0;
		}
	}
	//reset buttons 
	{
		if (!(GetKeyState(0x41) & SHIFTED))
		{
			buttons.a = false;
		}
		if (!(GetKeyState(0x44) & SHIFTED))
		{
			buttons.d = false;
		}
		if (!(GetKeyState(0x57) & SHIFTED))
		{
			buttons.w = false;
		}
		if (!(GetKeyState(0x53) & SHIFTED))
		{
			buttons.s = false;
		}
		if (!(GetKeyState(0x20) & SHIFTED))
		{
			buttons.space = false;
		}
	}
	if (abs(velocityX) > 0 && inAir == false && activeAnimation != WALKING_ANIMATION)
	{
		changeAnimation(WALKING_ANIMATION);
	}
	if (velocityX == 0 || inAir == true && activeAnimation != IDLE_ANIMATION)
	{
		changeAnimation(IDLE_ANIMATION);
	}
	Actor::update(time);
}
