#pragma once

#include "Brush.h"
#include <iostream>

namespace esne 
{
    class RoundBrush : public Brush
    {
        int radius = 0;

    protected:

    public:

        RoundBrush(int width, int depth) : Brush(width, depth)
        {

        }

        void setRadius(int new_radius)
        {
            radius = new_radius;
        }
    };
}