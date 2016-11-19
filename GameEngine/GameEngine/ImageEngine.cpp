#include "Main.h"

ImageEngine::ImageEngine(int givenWidth, int givenHeight, HWND hwnd)
{
	width = givenWidth;
	height = givenHeight;
	backBuffer = new Showable*[width*height];
	nullBackBuffer = new Showable*[width*height];
	midBuffer = new pixel[width*height];
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
	Bitmap* letters = new Bitmap("Letters.bmp");
	textEngine = new TextEngine(letters, allShowable, &showableLength, width, height);
	BITMAPINFO bmi;
	bmi.bmiHeader.biSize = sizeof(BITMAPINFO);
	bmi.bmiHeader.biWidth = width;
	bmi.bmiHeader.biHeight = height; // Order pixels from top to bottom
	bmi.bmiHeader.biPlanes = 1;
	bmi.bmiHeader.biBitCount = 32; 
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

void ImageEngine::present()
{
	allCollisions = new RECT[100];
	collisionLength = 0;
	activeBackground->present(midBuffer, allShowable, showableLength, NULL, allCollisions, collisionLength, backBuffer);
	std::clock_t time;
	for (int aaa = 0; aaa < showableLength; aaa++)
	{
		time = clock();
		allShowable[aaa]->update(time);
	}
	for (int aaa = 0; aaa < showableLength; aaa++)
	{
		allShowable[aaa]->present(midBuffer, aaa, allCollisions, collisionLength, backBuffer);
	}
	POINT* tempNullPoints;
	int tempNullPointsCount;
	//paint background onto nullPoints
	for (int aaa = 0; aaa < showableLength; aaa++)
	{
		tempNullPoints = allShowable[aaa]->getMainImage()->getNullPoints();
		tempNullPointsCount = allShowable[aaa]->getMainImage()->getNullPointsCount();
		for (int bbb = 0; bbb < tempNullPointsCount; bbb++)
		{
			midBuffer[((tempNullPoints[bbb].y + allShowable[aaa]->getY())*width) + tempNullPoints[bbb].x + allShowable[aaa]->getX()] = activeBackground->getMainImage()->getColor(tempNullPoints[bbb].x + allShowable[aaa]->getX(), tempNullPoints[bbb].y + allShowable[aaa]->getY());
		}
	}
	//paint collisions on backbuffer onto frontbuffer
	for (int iii = 0; iii < collisionLength; iii++)
	{
		for (int yCur = allCollisions[iii].top; yCur < allCollisions[iii].bottom; yCur++)
		{
			for (int xCur = allCollisions[iii].left; xCur < allCollisions[iii].right; xCur++)
			{
				if (backBuffer[xCur + (yCur*width)] != NULL)
				{
					midBuffer[xCur + (yCur*width)] = backBuffer[xCur + (yCur*width)]->getColor(xCur, yCur);
				}
			}
		}
	}
	std::memcpy((void*)frontBuffer, (void*)midBuffer, (sizeof(pixel)*(width*height)));
	std::memcpy((void*)backBuffer, (void*)nullBackBuffer, sizeof(Showable*)*width*height);
	delete[] allCollisions;
	collisionLength = 0;
}

void ImageEngine::cleanUp()
{
	Showable **tempArray;
	tempArray = new Showable*[100];
	int deletedCount = 0;
	int showableTemp = showableLength;
	for (int aaa = 0; aaa < showableTemp; aaa++)
	{
		if (allShowable[aaa]->getIsDead() == true)
		{
			showableLength--;
			delete allShowable[aaa];
			deletedCount++;
		}
		else
		{
			tempArray[aaa-deletedCount] = allShowable[aaa];
		}
	}
	std::memcpy(allShowable, tempArray, sizeof(Showable*) * 100);
	delete[] tempArray;
}

void ImageEngine::showText()
{
	textEngine->ShowText("PLEASE ALLOW ME TO TELL YOU THAT YOU ARE THE GREATEST");
}
