#pragma once
#include "Main.h"

class Showable;
class Bitmap;

class Actor : public Showable
{
private:
	int width;
	int height;
	double x;
	double y;
public:
	int paint(Showable ***depthCheck, int screenWidth, int screenHeight);
};
