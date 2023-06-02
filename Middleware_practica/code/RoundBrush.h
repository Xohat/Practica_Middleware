#pragma once

#include "Brush.h"

class RoundBrush : public Brush
{
public:

	RoundBrush(unsigned width, unsigned depth) : Brush(width, depth)
	{
		// rellenar el buffer con un círculo
	}
};