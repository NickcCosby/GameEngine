#include "GameState.h"

GameState::GameState(int givenWidth, int givenHeight, HWND hwnd)
{
	width = givenWidth;
	height = givenHeight;
	backBuffer = new Showable*[width*height];
	nullBackBuffer = new Showable*[width*height];
	for (int aaa = 0; aaa < height; aaa++)
	{
		for (int bbb = 0; bbb < width; bbb++)
		{
			backBuffer[(aaa*width) + bbb] = NULL;
			nullBackBuffer[(aaa*width) + bbb] = NULL;
		}
	}
	allShowable = new Showable*[100];
	showableLength = 0;
	allSprites = new Bitmap("ship1.bmp");
	player = new Pawn(width/2, height/2, allSprites, allShowable, showableLength, width, height);
	activeBackground = new Background("background.bmp", width, height);
	BITMAPINFO bmi;
	bmi.bmiHeader.biSize = sizeof(BITMAPINFO);
	bmi.bmiHeader.biWidth = width;
	bmi.bmiHeader.biHeight = -height; // Order pixels from top to bottom
	bmi.bmiHeader.biPlanes = 1;
	bmi.bmiHeader.biBitCount = 32; // last byte not used, 32 bit for alignment
	bmi.bmiHeader.biCompression = BI_RGB;
	bmi.bmiHeader.biSizeImage = 0;
	bmi.bmiHeader.biXPelsPerMeter = 0;
	bmi.bmiHeader.biYPelsPerMeter = 0;
	bmi.bmiHeader.biClrUsed = 0;
	bmi.bmiHeader.biClrImportant = 0;
	bmi.bmiColors[0].rgbBlue = 0;
	bmi.bmiColors[0].rgbGreen = 0;
	bmi.bmiColors[0].rgbRed = 0;
	bmi.bmiColors[0].rgbReserved = 0;
	HDC hdc = GetDC(hwnd);
	// Create DIB section to always give direct access to pixels
	hbmp = CreateDIBSection(hdc, &bmi, DIB_RGB_COLORS, (void**)&frontBuffer, NULL, 0);
	DeleteDC(hdc);
	//cleanUp();
}

void GameState::present()
{
	RECT* allCollisions = new RECT[100];
	int collisionLength = 0;
	activeBackground->present(frontBuffer, allShowable, showableLength, NULL, allCollisions, collisionLength, backBuffer);
	for (int aaa = 0; aaa < showableLength; aaa++)
	{
		allShowable[aaa]->update();
		allShowable[aaa]->present(frontBuffer, allShowable, showableLength, aaa, allCollisions, collisionLength, backBuffer);
	}
	for (int iii = 0; iii < collisionLength; iii++)
	{
		for (int yCur = allCollisions[iii].top; yCur < allCollisions[iii].bottom; yCur++)
		{
			for (int xCur = allCollisions[iii].right; xCur < allCollisions[iii].left; xCur++)
			{
				frontBuffer[xCur + (yCur*width)] = backBuffer[xCur + (yCur*width)]->getColor(xCur, yCur);
			}
		}
	}

	std::memcpy((void*)backBuffer, (void*)nullBackBuffer, sizeof(Showable*)*width*height);
}

void GameState::cleanUp()
{
	Showable **tempArray;
	tempArray = new Showable*[100];
	for (int aaa = 0; aaa < showableLength; aaa++)
	{
		if (allShowable[aaa]->getIsDead() == true)
		{
			showableLength--;
			delete allShowable[aaa];
		}
		else
		{
			tempArray[aaa] = allShowable[aaa];
		}
	}
	delete allShowable;
	allShowable = tempArray;
}
