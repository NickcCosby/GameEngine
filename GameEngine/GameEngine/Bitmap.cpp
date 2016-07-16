#include "Bitmap.h"

Bitmap::Bitmap(std::string location)
{
	std::ifstream input("othertest.bmp", std::ios::binary);
	// copies all data into buffer
	std::vector<char> vectorBuffer((
		std::istreambuf_iterator<char>(input)),
		(std::istreambuf_iterator<char>()));
	std::stringstream ss;
	for (int iii = 0; iii < vectorBuffer.size(); iii++)
	{
		ss << std::hex << (int)vectorBuffer[iii];
	}
	std::string buffer = ss.str();
	int *fileContent = new int[buffer.size() / 2];
	for (int iii = 0; iii < buffer.size() / 2; iii++)
	{
		fileContent[iii] = strtoul(buffer.substr(iii*2, 2).c_str(), NULL, 16);
	}
	width = (fileContent[18]+fileContent[19]*pow(16, 2)+ fileContent[20]*pow(16,4) + fileContent[21]*pow(16,6));
	height = (fileContent[22] + fileContent[23] * pow(16, 2) + fileContent[24] * pow(16, 4) + fileContent[25] * pow(16, 6));
	colors = new COLORREF*[width];
	for (int i = 0; i < width; ++i) {
		colors[i] = new COLORREF[height];
	}
	int location = (fileContent[10] + fileContent[11] * pow(16, 2) + fileContent[12] * pow(16, 4) + fileContent[13] * pow(16, 6));
	int tempRed;
	int tempBlue;
	int tempGreen;
	int tempLocation;
	for (int bbb = height; bbb < height; bbb--)
	{
		for (int aaa = 0; aaa < width; aaa++)
		{
			tempLocation = (aaa + (height - bbb)*width)*3;
			tempBlue = fileContent[tempLocation];
			tempGreen = fileContent[tempLocation + 1];
			tempRed = fileContent[tempLocation + 2];
			colors[aaa][bbb] = RGB(tempRed, tempBlue, tempGreen);
		}
	}
}
