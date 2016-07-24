#include "GameState.h"

GameState::GameState(int givenWidth, int givenHeight)
{
	width = givenWidth;
	height = givenHeight;
	backBuffer = new Showable**[width];
	for (int i = 0; i < width; ++i)
	{
		backBuffer[i] = new Showable*[height];
	}
	allShowable = new Showable*[100];
	showableLength = 0;
	allSprites = new Bitmap("ship1.bmp");
	Player = new Pawn(width/2, height/2, allSprites, allShowable, showableLength);
}

void GameState::present()
{
	for (int aaa = 0; aaa < showableLength; aaa++)
	{
		allShowable[aaa]->paint(backBuffer, width, height);
	}
	frontBuffer = new Bitmap(width, height);
	for (int bbb = 0; bbb < height; bbb++)
	{
		for (int ccc = 0; ccc < width; ccc++)
		{
			if (backBuffer[ccc][bbb] != NULL)
			{
				frontBuffer->setPixelColor(backBuffer[ccc][bbb]->getColor(ccc, bbb), ccc, bbb);
			}
		}
	}
	delete[] backBuffer;
	backBuffer = new Showable**[width];
	for (int i = 0; i < width; ++i)
	{
		backBuffer[i] = new Showable*[height];
	}
}
