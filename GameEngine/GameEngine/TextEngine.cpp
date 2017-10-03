
#include "Main.h"

TextEngine::TextEngine(Bitmap * allLettersGiven, Showable** givenAllShowable, int* givenShowableCount, int width, int height)
{
	allShowable = givenAllShowable;
	allLetters = allLettersGiven;
	showableLength = givenShowableCount;
	screenWidth = width;
	screenHeight = height;
	letters = new Bitmap*[26];
	RECT tempLetterPos;
	for (int iii = 0; iii < 27; iii++)
	{
		tempLetterPos.top = 80;
		tempLetterPos.left = iii * 50;
		tempLetterPos.right = (iii + 1) * 50;
		tempLetterPos.bottom = 0;
		letters[iii] = allLetters->createSubBitmap(tempLetterPos);
		letterSize[iii] = 50;
	}
}

void TextEngine::ShowText(std::string givenText)
{
	int nextX = 0;
	int nextY = 160;
	text = new Letter*[givenText.length()];
	for (int iii = 0; (UINT)iii < givenText.length(); iii++)
	{
		switch (givenText[iii])
		{
		case 'A':
			text[iii] = new Letter(nextX, nextY, letters[0], allShowable, showableLength, screenWidth, screenHeight);
			break;
		case 'B':
			text[iii] = new Letter(nextX, nextY, letters[1], allShowable, showableLength, screenWidth, screenHeight);
			break;
		case 'C':
			text[iii] = new Letter(nextX, nextY, letters[2], allShowable, showableLength, screenWidth, screenHeight);
			break;
		case 'D':
			text[iii] = new Letter(nextX, nextY, letters[3], allShowable, showableLength, screenWidth, screenHeight);
			break;
		case 'E':
			text[iii] = new Letter(nextX, nextY, letters[4], allShowable, showableLength, screenWidth, screenHeight);
			break;
		case 'F':
			text[iii] = new Letter(nextX, nextY, letters[5], allShowable, showableLength, screenWidth, screenHeight);
			break;
		case 'G':
			text[iii] = new Letter(nextX, nextY, letters[6], allShowable, showableLength, screenWidth, screenHeight);
			break;
		case 'H':
			text[iii] = new Letter(nextX, nextY, letters[7], allShowable, showableLength, screenWidth, screenHeight);
			break;
		case 'I':
			text[iii] = new Letter(nextX, nextY, letters[8], allShowable, showableLength, screenWidth, screenHeight);
			break;
		case 'J':
			text[iii] = new Letter(nextX, nextY, letters[9], allShowable, showableLength, screenWidth, screenHeight);
			break;
		case 'K':
			text[iii] = new Letter(nextX, nextY, letters[10], allShowable, showableLength, screenWidth, screenHeight);
			break;
		case 'L':
			text[iii] = new Letter(nextX, nextY, letters[11], allShowable, showableLength, screenWidth, screenHeight);
			break;
		case 'M':
			text[iii] = new Letter(nextX, nextY, letters[12], allShowable, showableLength, screenWidth, screenHeight);
			break;
		case 'N':
			text[iii] = new Letter(nextX, nextY, letters[13], allShowable, showableLength, screenWidth, screenHeight);
			break;
		case 'O':
			text[iii] = new Letter(nextX, nextY, letters[14], allShowable, showableLength, screenWidth, screenHeight);
			break;
		case 'P':
			text[iii] = new Letter(nextX, nextY, letters[15], allShowable, showableLength, screenWidth, screenHeight);
			break;
		case 'Q':
			text[iii] = new Letter(nextX, nextY, letters[16], allShowable, showableLength, screenWidth, screenHeight);
			break;
		case 'R':
			text[iii] = new Letter(nextX, nextY, letters[17], allShowable, showableLength, screenWidth, screenHeight);
			break;
		case 'S':
			text[iii] = new Letter(nextX, nextY, letters[18], allShowable, showableLength, screenWidth, screenHeight);
			break;
		case 'T':
			text[iii] = new Letter(nextX, nextY, letters[19], allShowable, showableLength, screenWidth, screenHeight);
			break;
		case 'U':
			text[iii] = new Letter(nextX, nextY, letters[20], allShowable, showableLength, screenWidth, screenHeight);
			break;
		case 'V':
			text[iii] = new Letter(nextX, nextY, letters[21], allShowable, showableLength, screenWidth, screenHeight);
			break;
		case 'W':
			text[iii] = new Letter(nextX, nextY, letters[22], allShowable, showableLength, screenWidth, screenHeight);
			break;
		case 'X':
			text[iii] = new Letter(nextX, nextY, letters[23], allShowable, showableLength, screenWidth, screenHeight);
			break;
		case 'Y':
			text[iii] = new Letter(nextX, nextY, letters[24], allShowable, showableLength, screenWidth, screenHeight);
			break;
		case 'Z':
			text[iii] = new Letter(nextX, nextY, letters[25], allShowable, showableLength, screenWidth, screenHeight);
			break;
		}
		nextX += 50;
		if (nextX >= 1600 - 50)
		{
			nextY -= 80;
			nextX = 0;
		}
	}
}
