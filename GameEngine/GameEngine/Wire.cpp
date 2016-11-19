#include "Main.h"

Wire::Wire(int startX, int startY, Bitmap * allSprites, Showable **& allShowable, int * showableLength, int width, int height, int wireIndexGiven) : Actor(startX, startY, allSprites, allShowable, showableLength, width, height)
{
	wirePositions = new Bitmap*[7];
	RECT tempRECT;
	tempRECT.top = 600;
	tempRECT.bottom = 550;
	tempRECT.left = 0;
	tempRECT.right = 455;
	wirePositions[0] = allSprites->createSubBitmap(tempRECT);
	tempRECT.bottom = 400;
	tempRECT.right = 455;
	tempRECT.left = 455 * 2;
	wirePositions[1] = allSprites->createSubBitmap(tempRECT);
	tempRECT.bottom = 200;
	tempRECT.right = 455 * 2;
	tempRECT.left = 455 * 3;
	wirePositions[2] = allSprites->createSubBitmap(tempRECT);
	tempRECT.bottom = 0;
	tempRECT.right = 455 * 3;
	tempRECT.left = 455 * 4;
	wirePositions[3] = allSprites->createSubBitmap(tempRECT);
	tempRECT.bottom = 400;
	tempRECT.right = 455 * 4;
	tempRECT.left = 455 * 5;
	wirePositions[4] = allSprites->createSubBitmap(tempRECT);
	tempRECT.bottom = 200;
	tempRECT.right = 455 * 5;
	tempRECT.left = 455 * 6;
	wirePositions[5] = allSprites->createSubBitmap(tempRECT);
	tempRECT.bottom = 0;
	tempRECT.right = 455 * 6;
	tempRECT.left = 455 * 7;
	wirePositions[6] = allSprites->createSubBitmap(tempRECT);
	wireIndex = wireIndexGiven;
	switch (wireIndex)
	{
	case 0:
		mainImage = wirePositions[0];
		x = 1250;
		y = 820 - 50;
		break;
	case 1:
		mainImage = wirePositions[1];
		x = 1250;
		y = 820 - 250;
		break;
	case 2:
		mainImage = wirePositions[2];
		x = 1250;
		y = 820 - 450;
		break;
	case 3:
		mainImage = wirePositions[3];
		x = 1250;
		y = 820 - 650;
	case 4:
		mainImage = wirePositions[0];
		x = 350;
		y = 820 - 50;
		break;
	case 5:
		mainImage = wirePositions[4];
		x = 350;
		y = 820 - 250;
		break;
	case 6:
		mainImage = wirePositions[5];
		x = 350;
		y = 820 - 450;
		break;
	case 7:
		mainImage = wirePositions[6];
		x = 350;
		y = 820 - 650;
		break;
	}
}

