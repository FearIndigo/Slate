﻿#include "thumbnail.hpp"
#include <string>
#include <iostream>

namespace Slate
{
    Thumbnail::Thumbnail(const char* text)
    {
        // Set title
        title = text;
        
        // Set text color
        color = {128,128,128};
            
        // Load font
        if (!font.LoadFont("matrix/fonts/5x7.bdf")) {
            fprintf(stderr, "Couldn't load font '%s'\n", "matrix/font/4x6.bdf");
            throw std::invalid_argument("Could load font used for thumbnail.");
        }
    }

    void Thumbnail::Display(rgb_matrix::FrameCanvas *canvas, const unsigned int frame_time)
    {
        length = rgb_matrix::DrawText(canvas, font,
                                    x + 32, 29 + font.baseline(),
                                    color, NULL,
                                    title, 0);
        std::cout   << "Step: " << std::to_string(step)) << "\n"
                    << "X: " << std::to_string(x)) << "\n"
                    << "Length: " << std::to_string(length)) << "\n\n";
        
        step += frame_time;
        if(step >= 100)
        {
            step = step % 100;
            if(--x + length + 32 < 0)
                x = 0;
        }
    }
}
