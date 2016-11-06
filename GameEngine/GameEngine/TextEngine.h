#pragma once
#include "Letter.h"

class TextEngine
{
private:
	Bitmap* allLetters;
	Bitmap** letters;
	int letterSize[26];
	Letter** text;
	Showable** allShowable;
	int *showableLength;
	int screenWidth;
	int screenHeight;
public:
	TextEngine(Bitmap * allLettersGiven, Showable** givenAllShowable, int* givenShowableCount, int width, int height);
	void ShowText(std::string givenText);
};