#include "thumbnail.hpp"

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
            throw std::invalid_argument("Could load font use for Ponglord.");
        }
    }

    void Thumbnail::Display(rgb_matrix::FrameCanvas *canvas, const unsigned int frame_time)
    {
        length = rgb_matrix::DrawText(canvas, font,
                                    x + 32, 30 + font.baseline(),
                                    color, NULL,
                                    title, 0);
            
        step += frame_time;
        if(step > 100)
        {
            step = 0;
            if(--x + length + 32 < 0)
                x = 0;
        }
    }
}
