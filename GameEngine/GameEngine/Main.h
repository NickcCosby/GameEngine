#pragma once
struct pixel {
	union {
		struct {
			unsigned char b, g, r, a;
		};
		int val;
	};
	pixel() {
		val = 0;
	}
};

#include <Windows.h>
#include <string>
#include <fstream>
#include <iterator>
#include <vector>
#include <sstream>
#include <stdlib.h>
#include <math.h>
#include "Win32App.h"
#include "GameState.h"
#include "Showable.h"
#include "Bitmap.h"

union KeyState
{
	LPARAM lparam;

	struct
	{
		unsigned nRepeatCount : 16;
		unsigned nScanCode : 8;
		unsigned nExtended : 1;
		unsigned nReserved : 4;
		unsigned nContext : 1;
		unsigned nPrev : 1;
		unsigned nTrans : 1;
	};
};

