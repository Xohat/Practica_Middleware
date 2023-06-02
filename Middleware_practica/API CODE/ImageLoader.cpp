/**
@file ImageLoader.cpp
@brief Implementación del encargado de cargar imagenes
@author Arturo Vilar Carretero
*/

// Copyright (c) 2023 Arturo / arturovilarc@gmail.com
// 2023.5 - 2023.06

#include "ImageLoader.h"

void ImageLoader::load_image()
{
    unsigned char* img = stbi_load(current_image->get_path().c_str(), &width, &height, &channels, 1);

    if (img == nullptr)
    {
        return;
    }

    // Se settea la width, la height y luego el espacio del 
    // nuevo buffer mandanbdole los dos datos de width y height
    current_image->set_width(width);
    current_image->set_depth(height);
    current_image->set_buffer(width, height);

    // Itera en la imgen y settea los valores del height buffer
    for (int x = 0; x < width; x++)
    {
        for (int z = 0; z < height; z++)
        {
            // Convierte el valor de pixeles en HeightBuffer.height
            float new_height = static_cast<float>(img[x + width * z]);
            current_image->set_height(x, z, new_height);
        }
    }

    // Libera los datos tras esto
    stbi_image_free(img);
}