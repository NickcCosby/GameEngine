#include "Actor.h"

int Actor::paint(Showable *** depthCheck, int screenWidth, int screenHeight)
{
	for (int iii = 0; iii < height; iii++)
	{
		for (int bbb = 0; bbb < width; bbb++)
		{
			if (mainImage->getColor(bbb, iii) != NULL)
			{
				if (depthCheck[bbb][iii] == NULL)
					depthCheck[bbb][iii] = this;
				else
				{
					if (depthCheck[bbb][iii]->getDepth() < depth)
						depthCheck[bbb][iii] = this;
				}
			}
		}
	}
	return 0;
}
