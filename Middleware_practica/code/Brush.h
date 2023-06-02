#pragma once

#include "HeightBuffer.h"

class Brush : public HeightBuffer
{

protected:

	Brush(unsigned width, unsigned depth) : HeightBuffer(width, depth)
	{

	}
};