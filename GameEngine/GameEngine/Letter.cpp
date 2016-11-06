#include "Main.h"

Letter::Letter(int startX, int startY, Bitmap *allSprites, Showable **&allShowable, int *showableLength, int width, int height) : Showable(startX, startY, allShowable, showableLength, width, height)
{
	mainImage = allSprites;
	depth = 1;
}
