#pragma once

#include <vector>

using std::vector;

class HeightBuffer
{

	unsigned width;
	unsigned depth;

	vector<float> buffer;

public:

	HeightBuffer(unsigned width, unsigned depth) : 
		width(width),
		depth(depth), 
		buffer(width* depth)
	{
	}

	float get_width() const
	{
		return width;
	}

	float get_depth() const
	{
		return depth;
	}

	void set_height(int x, int z, int new_height)
	{
		if (x >= 0 && z >= 0 && x < width && z < depth)
		{
			buffer[x * depth + z] = new_height;
		}
	}

	float get_height(int x, int z) const
	{
		if (x >= 0 && z >= 0 && x < width && z < depth)
		{
			return buffer[x * depth + z];
		}
	}
};