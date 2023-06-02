#pragma once

#include "HeightBuffer.h"

namespace esne 
{
	class ImageController 
	{
		HeightBuffer* current_image = new HeightBuffer(0, 0);

	public:

		ImageController(HeightBuffer& given_image)
		{
			*current_image = given_image;
		}

		void paint(HeightBuffer& current_image, float new_color, int pixel_x, int pixel_y)
		{
			current_image.set_height(pixel_x, pixel_y, (int)new_color);
		}
	};
}
