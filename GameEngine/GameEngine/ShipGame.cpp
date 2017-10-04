#include "Main.h"

ShipGame::ShipGame(Win32App * me, int width, int height, HWND hwnd) : GameState(me, width, height, hwnd)
{
	Bitmap* ship = new Bitmap("realShip.bmp");
	player = new Ship(width / 2, height / 2, ship, imageEngine->getAllShowable(), imageEngine->getShowableLengthPtr(), width, height);
	backGround = new Background("background.bmp", width, height);
	Bitmap* enemySprite = new Bitmap("RealEnemyShip.bmp");
	EnemyShip* enemy = new EnemyShip(width / 2, height / 4, enemySprite, imageEngine->getAllShowable(), imageEngine->getShowableLengthPtr(), width, height);
	imageEngine->setActiveBackground(backGround);
}

void ShipGame::inputReact(WPARAM keyPressed, bool down)
{
	switch (keyPressed)
	{
	case 0x57:
		player->inputReact('w', down);
		break;
	case 0x53:
		player->inputReact('s', down);
		break;
	case 0x41:
		player->inputReact('a', down);
		break;
	case 0x44:
		player->inputReact('d', down);
		break;
	case 0x20:
		player->inputReact(' ', down);
		break;
	case 0x52:
		player->inputReact('r', down);
		break;
	}
}

void ShipGame::inputReact(int x, int y, bool left)
{
}
