#pragma once

#include <Windows.h>
#include <string>
#include <fstream>
#include <iterator>
#include <vector>
#include <sstream>
#include <stdlib.h>
#include <math.h>
#include <ctime>
#include <windowsx.h>
#include "EngineHeaders.h"
#include "ShipGameHeaders.h"
#include "RunningGameHeaders.h"


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


#define getArrayPos(x,y) ((y*x)+x)

template <typename T> int sgn(T val) {
	return (T(0) < val) - (val < T(0));
}