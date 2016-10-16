#pragma once

class Bitmap
{
private:
	int width;
	int height;
public:
	pixel *colors;
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

};

