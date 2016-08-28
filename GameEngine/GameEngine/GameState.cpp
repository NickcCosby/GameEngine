#include "GameState.h"

GameState::GameState(int givenWidth, int givenHeight, HWND hwnd)
{
	width = givenWidth;
	height = givenHeight;
	backBuffer = new Showable**[width];
	for (int i = 0; i < width; ++i)
	{
		backBuffer[i] = new Showable*[height];
	}
	for (int aaa = 0; aaa < height; aaa++)
	{
		for (int bbb = 0; bbb < width; bbb++)
		{
			backBuffer[bbb][aaa] = NULL;
		}
	}
	allShowable = new Showable*[100];
	showableLength = 0;
	allSprites = new Bitmap("ship1.bmp");
	player = new Pawn(width/2, height/2, allSprites, allShowable, showableLength);
	activeBackground = new Background("background.bmp", allShowable, showableLength);
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
	for (int aaa = 0; aaa < showableLength; aaa++)
	{
		allShowable[aaa]->update();
		allShowable[aaa]->paint(backBuffer, width, height);
	}
	pixel *temp;
	for (int heightCur = 0; heightCur < height; heightCur++)
	{
		for (int widthCur = 0; widthCur < width; widthCur++)
		{
			if (backBuffer[widthCur][heightCur] != NULL)
			{
				temp = &frontBuffer[heightCur*width + widthCur];
				temp->b = backBuffer[widthCur][heightCur]->getColor(widthCur, heightCur).b;
				temp->g = backBuffer[widthCur][heightCur]->getColor(widthCur, heightCur).g;
				temp->r = backBuffer[widthCur][heightCur]->getColor(widthCur, heightCur).r;
			}
		}
	}
	for (int zzz = 0; zzz < height; zzz++)
	{
		for (int xxx = 0; xxx < width; xxx++)
		{
			backBuffer[xxx][zzz] = NULL;
		}
	}
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
