#include "Showable.h"

Showable::Showable(Showable ** allShowable, int &showableLength)
{
	allShowable[showableLength] = this;
	showableLength++;
}
