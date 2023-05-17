

class App
{

	HeightBuffer height_buffer;
	
	
	vector<

};


class HeightBuffer
{
	
	unsigned width;
	unsigned depth;

	vector<float> buffer;
	
public:

	HeightBuffer(unsigned width, unsigned depth)
	:
		width (width),
		depth (depth)
		buffer(width * depth)
	{
	}
	
	float get_width () const
	{
		return height;
	}
		
	float get_depth () const
	{
		return depth;
	}
	
	void set_height (int x, int z, int new_height)
	{
		if (x >= 0 && z >= 0 && x < width && z < depth)
		{
			buffer[x * depth + z] = new_height;
		}
	}

	float get_height (int x, int z) const
	{
		if (x >= 0 && z >= 0 && x < width && z < depth)
		{
			return buffer[x * depth + z];
		}
	}
};

class Brush : public HeightBuffer
{

protected:

	Brush(unsigned width, unsigne depth) : HeightBuffer(width, depth)
	{
	}

};


class RoundBrush : public Brush
{
public:

	RoundBrush(unsigned width, unsigne depth) : Brush(width, depth)
	{
		// rellenar el buffer con un círculo
	}

}

class Blitter
{

	HeightBuffer & target;
	
public:

	Blitter(HeightBuffer & buffer) : target(buffer)
	{
	}
	
	void blit (int center_x, int center_z, const HeightBuffer & source)
	{
		unsigned source_width = source.get_width ();
		unsigned source_depth = source.get_depth ();
		unsigned half_width   = source_width / 2;
		unsigned half_depth   = source_depth / 2;
	
		for (unsigned z = 0; z < source_depth; ++z)
		{
			for (unsigned x = 0; x < source_width; ++x)
			{
				float y = source.get_height (x, z);
				
				target.set_height (center_x + x + half_width, center_z + z + half_depth, y);
			}
		}
	}

};
