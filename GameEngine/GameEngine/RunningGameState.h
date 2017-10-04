#pragma once
#include "GameState.h"
#include "RunnerPawn.h"
#include "RunnerEnemy.h"

class RunningGameState : public GameState
{
protected:
	RunnerPawn* runner;
	RunnerEnemy* enemy;
	Bitmap* collisionMap;
public:
	RunningGameState::RunningGameState(Win32App *me, int width, int height, HWND hwnd);
	void RunningGameState::inputReact(WPARAM keyPressed, bool down);
	void RunningGameState::inputReact(int x, int y, bool left);
};