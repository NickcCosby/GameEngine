#pragma once

class Bitmap
{
private:
	int width;
	int height;
	pixel *colors;
	POINT* nullPoints;
	int nullPointsCount;
public:
	Bitmap* rotate(float angle);
	inline void addNullPoint(int x, int y)
	{
		nullPoints[nullPointsCount].x = x;
		nullPoints[nullPointsCount].y = y;
		nullPointsCount++;
	}
	inline POINT* Bitmap::getNullPoints()
	{
		return nullPoints;
	}
	int getNullPointsCount()
	{
		return nullPointsCount;
	}
	inline pixel Bitmap::getColor(int x, int y)
	{
		return colors[((width*y)+x)];
	}
	inline pixel* Bitmap::getRowColors(int y)
	{
		return &colors[width*y];
	}
	inline pixel* Bitmap::getRowColors(int y, int offset)
	{
		return &colors[(width*y) + offset];
	}
	inline pixel* Bitmap::getColors()
	{
		return colors;
	}
	int getWidth()
	{
		return width;
	}
	int getHeight()
	{
		return height;
	}
	Bitmap(std::string location);
	Bitmap(int width, int height);
	~Bitmap();
	void setPixelColor(pixel tempColor, int x, int y);
	Bitmap* createSubBitmap(RECT space);
	Bitmap()
	{

	}
};

