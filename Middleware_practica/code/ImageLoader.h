/**
@file ImageLoader.h
@brief Archivo encargado de cargar imagenes
@author Arturo Vilar Carretero
*/

// Copyright (c) 2023 Arturo / arturovilarc@gmail.com
// 2023.5 - 2023.06

#pragma once

#include "stb_image.h"

#include "HeightBuffer.h"
#include "API.h"

class API ImageLoader
{
    int width;
    int height;
    int channels;

    HeightBuffer* current_image = new HeightBuffer(0, 0);

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

    /// <summary>
    /// Carga la imagen por medio de la libreria stb_image.h
    /// Detalles en el cpp
    /// </summary>
    void load_image();
};