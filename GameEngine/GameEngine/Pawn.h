#pragma once
#include "Actor.h"

struct buttons {
	union {
		struct {
			bool a, s, d, w, space;
		};
		int val;
	};
	buttons() {
		val = 0;
	}
};

struct lastPressedButtons
{
	std::clock_t a, s, d, w, space;
};


class Pawn : virtual public Actor
{
protected:
	buttons buttons;
	lastPressedButtons lastPressedButtons;
public:
	Pawn(int startX, int startY, Bitmap *allSprites, Showable **allShowable, int *showableLength, int width, int height);
	virtual void collide(Showable *otherShowable) = 0;
	virtual void inputReact(char input, bool down) = 0;
	void addCollisions(RECT collisionRECT)
	{

	}
};