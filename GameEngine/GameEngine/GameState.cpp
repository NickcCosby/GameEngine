#include "GameState.h"

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
			frontBuffer->setPixelColor(backBuffer[ccc][bbb]->getColor(ccc, bbb), ccc, bbb);
		}
	}
}
