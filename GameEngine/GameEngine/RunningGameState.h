#pragma once
#include "GameState.h"
#include "RunnerPawn.h"

class RunningGameState : public GameState
{
protected:
	RunnerPawn* runner;
	Bitmap* collisionMap;
public:
	RunningGameState::RunningGameState(Win32App *me, int width, int height, HWND hwnd);
	void RunningGameState::inputReact(WPARAM keyPressed, bool down);
	void RunningGameState::inputReact(int x, int y, bool left);
};