﻿#include "display.hpp"

namespace Slate
{
    Display::Display(const char* hardwareMapping, const int rows, const int cols, const bool showRefresh)
    {
        RGBMatrix::Options defaults;
        defaults.hardware_mapping = hardwareMapping;
        defaults.rows = rows;
        defaults.cols = cols;
        defaults.show_refresh_rate = false;
        *canvas = RGBMatrix::CreateFromFlags(&argc, &argv, &defaults);
        if (canvas == NULL)
            throw std::invalid_argument( "Failed to create canvas." );
    }

    Display::~Display()
    {
        if (canvas == NULL) return;
        
        canvas->Clear();
        delete canvas;
    }
}