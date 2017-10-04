#pragma once
#include "GameState.h"
#include "Pawn.h"

class ShipGame : public GameState
{
private:
	Ship* player;
public:
	ShipGame(Win32App* me, int width, int height, HWND hwnd);
	void inputReact(WPARAM keyPressed, bool down);
	void inputReact(int x, int y, bool left);
};
