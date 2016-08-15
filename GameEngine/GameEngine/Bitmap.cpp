#include "Bitmap.h"
#include <iterator>

inline pixel Bitmap::getColor(int x, int y)
{
	return colors[x][y];
}

Bitmap::Bitmap(std::string location)
{
	std::ifstream input(location, std::ios::binary);
	// copies all data into buffer
	std::vector<UINT> vectorBuffer((std::istreambuf_iterator<char>(input)), (std::istreambuf_iterator<char>()));
	UINT *fileContent = new UINT[vectorBuffer.size()];
	for (UINT iii = 0; iii < vectorBuffer.size(); iii++)
	{
		fileContent[iii] = (UINT)vectorBuffer[iii];
		if (fileContent[iii] > 255)
		{
			fileContent[iii] -= 4294967040;
		}
	}
	width = (fileContent[18]+fileContent[19]*pow(16, 2)+ fileContent[20]*pow(16,4) + fileContent[21]*pow(16,6));
	height = (fileContent[22] + fileContent[23] * pow(16, 2) + fileContent[24] * pow(16, 4) + fileContent[25] * pow(16, 6));
	colors = new pixel*[width];
	for (int i = 0; i < width; ++i)
	{
		colors[i] = new pixel[height];
	}
	int colorsLocation = (fileContent[10] + fileContent[11] * pow(16, 2) + fileContent[12] * pow(16, 4) + fileContent[13] * pow(16, 6));
	int tempRed;
	int tempBlue;
	int tempGreen;
	int tempLocation;
	for (int bbb = height; bbb >= 0; bbb--)
	{
		for (int aaa = 0; aaa < width; aaa++)
		{
			tempLocation = (((aaa + (height - bbb)*width)*3) + colorsLocation);
			colors[aaa][bbb].b = fileContent[tempLocation];
			colors[aaa][bbb].g = fileContent[tempLocation + 1];
			colors[aaa][bbb].r = fileContent[tempLocation + 2];
		}
	}
}

Bitmap::Bitmap(int givenWidth, int givenHeight)
{
	width = givenWidth;
	height = givenHeight;
	colors = new pixel*[width];
	for (int i = 0; i < width; ++i)
	{
		colors[i] = new pixel[height];
	}
}

Bitmap::~Bitmap()
{
	for (int iii = 0; iii < width; iii++)
	{
			delete[] colors[iii];
	}
}

void Bitmap::setPixelColor(pixel tempColor, int x, int y)
{
	colors[x][y] = tempColor;
}

Bitmap* Bitmap::createSubBitmap(RECT space)
{
	int width, height;
	height = space.bottom - space.top;
	width = space.right - space.left;
	Bitmap *tempBitmap = new Bitmap(width, height);
	for (int curHeight = space.top; curHeight <= space.bottom; curHeight++)
	{
		for (int curWidth = space.left; curWidth <= space.right; curWidth++)
		{
			tempBitmap->setPixelColor(this->getColor(curWidth, curHeight), curWidth - space.left, curHeight - space.top);
		}
	}
	return tempBitmap;
}
