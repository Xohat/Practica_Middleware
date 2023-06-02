
#include "ImageLoader.h"

namespace esne 
{
    void ImageLoader::load_image()
    {
        unsigned char* img = stbi_load(current_image->get_path().c_str(), &width, &height, &channels, 1);

        if (img == nullptr)
        {
            return;
        }

        // Set the width and height of the image in the HeightBuffer
        current_image->set_width(width);
        current_image->set_depth(height);
        current_image->set_buffer(width, height);

        // Iterate through the image and set the height buffer values
        for (int x = 0; x < width; x++)
        {
            for (int z = 0; z < height; z++)
            {
                // Convert pixel value to height, this might need to be scaled depending on your use case
                float new_height = static_cast<float>(img[x + width * z]);
                current_image->set_height(x, z, new_height);
            }
        }

        // Don't forget to free the image data
        stbi_image_free(img);
    }
}