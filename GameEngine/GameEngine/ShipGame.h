#pragma once
#include "GameState.h"
#include "Pawn.h"
#include "Ai.h"

class ShipGame : public GameState
{
private:
	Pawn* player;
	Background* backGround;
public:
	ShipGame(Win32App* me, int width, int height, HWND hwnd);
	void inputReact(WPARAM keyPressed, bool down);
	void inputReact(int x, int y, bool left);
};
