#pragma once

#include "HeightBuffer.h"

namespace esne 
{
	class Brush
	{

	protected:

		HeightBuffer heightBuffer;

		bool is_active = false;

		float current_color = -1;

		int width;
		int height;

	public:

		Brush(unsigned given_width, unsigned given_depth) : heightBuffer(given_width, given_depth)
		{

		}

		bool get_active() 
		{
			return is_active;
		}

		void set_inactive() 
		{
			is_active = false;
		}

		void set_active() 
		{
			is_active = true;
		}

		float get_color() 
		{
			return current_color;
		}

		void set_color(float given_color) 
		{
			current_color = given_color;
		}

		void set_width(int new_width) 
		{
			width = new_width;
		}

		void set_height(int new_height)
		{
			height = new_height;
		}

		int get_width() 
		{
			return width;
		}

		int get_height()
		{
			return height;
		}
	};
}