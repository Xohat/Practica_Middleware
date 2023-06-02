#pragma once

#include "HeightBuffer.h"

class Blitter
{

	HeightBuffer& target;

public:

	Blitter(HeightBuffer& buffer) : target(buffer)
	{
	}

	void blit(int center_x, int center_z, const HeightBuffer& source)
	{
		unsigned source_width = source.get_width();
		unsigned source_depth = source.get_depth();
		unsigned half_width = source_width / 2;
		unsigned half_depth = source_depth / 2;

		for (unsigned z = 0; z < source_depth; ++z)
		{
			for (unsigned x = 0; x < source_width; ++x)
			{
				float y = source.get_height(x, z);

				target.set_height(center_x + x + half_width, center_z + z + half_depth, y);
			}
		}
	}

};
