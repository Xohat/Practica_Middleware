#pragma once

#include "stb_image.h"
#include "stb_image_resize.h"

#include "HeightBuffer.h"

namespace esne 
{
    class ImageLoader
    {
        int width;
        int height;
        int channels;

        HeightBuffer* current_image = new HeightBuffer(0,0);

    public:

        ImageLoader(HeightBuffer& given_current_image)
        {
            current_image = &given_current_image;
            load_image();
        }

        void change_image(HeightBuffer& new_image)
        {
            current_image = &new_image;
            load_image();
        }

        void load_image();
    };
}