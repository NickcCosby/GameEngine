#pragma once
#include "Main.h"

class Bitmap;
class Actor;

class Showable
{
protected:
	Bitmap *mainImage;
public:
	int paint(); //adds image onto back buffer
};
