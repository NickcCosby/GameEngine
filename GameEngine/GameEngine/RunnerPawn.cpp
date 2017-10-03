#include "Main.h"
#define SHIFTED 0x8000

RunnerPawn::RunnerPawn(int startX, int startY, Bitmap * allSprites, Showable ** allShowable, int * showableLength, int width, int height, Bitmap * CollisionMapGiven) : Pawn(startX, startY, allSprites, allShowable, showableLength, width, height)
{
	collisionMap = CollisionMapGiven;
	depth = .75;
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

void RunnerPawn::setInAir(bool inAirGiven)
{
	inAir = inAirGiven;
	if (inAir)
	{
		accelerationY = -500;
		//set x/y moving velocity to diff
	}
	else
	{
		accelerationY = 0;
		velocityY = 0;
	}
}

void RunnerPawn::update(std::clock_t time)
{
	//falling/ground collision
	{
		int whiteColor = 765;
		//check for all on bottom row
		for (int iii = x; iii < mainImage->getWidth() + x; iii++)
		{
			//if bottom row is in collision go 1 above
			if (collisionMap->getColor(iii, y).r + collisionMap->getColor(iii, y).g + collisionMap->getColor(iii, y).b != whiteColor)
			{
				do
				{
					y++;
				} while (collisionMap->getColor(iii, y).r + collisionMap->getColor(iii, y).g + collisionMap->getColor(iii, y).b != whiteColor);
				setInAir(false);
				iii = x;
			}
			//if bottom row is not 1 above collision, fall
			else if (collisionMap->getColor(iii, y - 2).r + collisionMap->getColor(iii, y - 2).g + collisionMap->getColor(iii, y - 2).b == whiteColor)
			{
				setInAir(true);
			}
		}
	}
	//movement
	{
		if (buttons.a == true)
		{
			if (lastPressedButtons.a == 0)
			{
				lastPressedButtons.a = time;
			}
			velocityX = (int)-(1 / (2 * ((time - lastPressedButtons.d) / (double)CLOCKS_PER_SEC) + .02)) - 200;
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
			setInAir(true);
			velocityY = 300;
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
	Actor::update(time);
}
