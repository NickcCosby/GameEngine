#include "Main.h"
#include <iterator>

//still needs implementation... probably
Bitmap * Bitmap::rotate(float angle)
{
	//Bitmap* tempBitmap;
	//return tempBitmap;
	return nullptr;
}

Bitmap::Bitmap(std::string location)
{
	std::ifstream input(location, std::ios::binary);
	// copies all data into buffer
	if (_heapchk() != _HEAPOK)
		DebugBreak();
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
	colors = new pixel[width*height];
	nullPoints = new POINT[width*height];
	nullPointsCount = 0;
	int colorsLocation = (fileContent[10] + fileContent[11] * pow(16, 2) + fileContent[12] * pow(16, 4) + fileContent[13] * pow(16, 6));
	int tempLocation;
	int colorsWritten = 0;
	for (int bbb = height; bbb > 0; bbb--)
	{
		for (int aaa = 0; aaa < width; aaa++)
		{
			//tempLocation = (((aaa + (height - bbb)*width)*3) + colorsLocation);
			tempLocation = (colorsWritten * 3) + colorsLocation;
			colors[colorsWritten].b = fileContent[tempLocation];
			colors[colorsWritten].g = fileContent[tempLocation + 1];
			colors[colorsWritten].r = fileContent[tempLocation + 2];
			if (colors[colorsWritten].b == 150 && colors[colorsWritten].g == 150 && colors[colorsWritten].r == 150)
			{
				nullPoints[nullPointsCount].x = colorsWritten % width;
				nullPoints[nullPointsCount].y = (int)colorsWritten/(int)width;
				nullPointsCount++;
			}
			colorsWritten++;
		}
	}
}

Bitmap::Bitmap(int givenWidth, int givenHeight)
{
	width = givenWidth;
	height = givenHeight;
	nullPoints = new POINT[width*height];
	nullPointsCount = 0;
	colors = new pixel[width*height];
}

Bitmap::~Bitmap()
{
		delete[] colors;
}

void Bitmap::setPixelColor(pixel tempColor, int x, int y)
{
	colors[x + (width*y)] = tempColor;
}

Bitmap* Bitmap::createSubBitmap(RECT space)
{
	int width, height;
	height = space.top - space.bottom;
	width = space.right - space.left;
	Bitmap *tempBitmap = new Bitmap(width, height);
	for (int curHeight = space.bottom; curHeight < space.top; curHeight++)
	{
		for (int curWidth = space.left; curWidth < space.right; curWidth++)
		{
			tempBitmap->setPixelColor(this->getColor(curWidth, curHeight), curWidth - space.left, curHeight - space.bottom);
			if (this->getColor(curWidth, curHeight).b == 150 && this->getColor(curWidth, curHeight).g == 150 && this->getColor(curWidth, curHeight).r == 150)
			{
				tempBitmap->addNullPoint(curWidth - space.left, curHeight - space.bottom);
			}
		}
	}
	return tempBitmap;
}
