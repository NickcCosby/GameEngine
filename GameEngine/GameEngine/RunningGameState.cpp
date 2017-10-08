#include "Main.h"

RunningGameState::RunningGameState(Win32App * me, int width, int height, HWND hwnd) : GameState(me, width, height, hwnd)
{
	//Bitmap* whoCare = new Bitmap("superTest.bmp");
	collisionMap = new Bitmap("Plate.bmp");
	backGround = new Background("Plate.bmp", width, height);
	Bitmap* runnerImage = new Bitmap("RunnerGuy.bmp");
	Bitmap* enemyImage = new Bitmap("RealEnemyShip.bmp");
	runner = new RunnerPawn(width / 2, height / 2 + 100, runnerImage, imageEngine->getAllShowable(), imageEngine->getShowableLengthPtr(), width, height, collisionMap);
	enemy = new RunnerEnemy(1600, 0, enemyImage, imageEngine->getAllShowable(), imageEngine->getShowableLengthPtr(), width, height, collisionMap);
	imageEngine->setActiveBackground(backGround);
}


void RunningGameState::inputReact(WPARAM keyPressed, bool down)
{
	switch (keyPressed)
	{
	case 0x57:
		runner->inputReact('w', down);
		break;
	case 0x53:
		runner->inputReact('s', down);
		break;
	case 0x41:
		runner->inputReact('a', down);
		break;
	case 0x44:
		runner->inputReact('d', down);
		break;
	case 0x20:
		runner->inputReact(' ', down);
		break;
	case 0x52:
		runner->inputReact('r', down);
		break;
	}
}

void RunningGameState::inputReact(int x, int y, bool left)
{
}