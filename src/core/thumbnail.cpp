#include "thumbnail.hpp"

namespace Slate
{
    Thumbnail::Thumbnail(const char* text)
    {
        // Set title
        title = text;
        
        // Set text color
        color = {128,128,128};

        // Set time it takes to scroll the text one pixel
        stepTime = 50;

        // Set how long it takes for the text to initially start scrolling
        firstStep = 500;
        
        // Load font
        if (!font.LoadFont("matrix/fonts/4x6.bdf")) {
            fprintf(stderr, "Couldn't load font '%s'\n", "matrix/font/4x6.bdf");
            throw std::invalid_argument("Could load font used for thumbnail.");
        }

        // Reset to starting position
        Reset();
    }

    void Thumbnail::Display(rgb_matrix::FrameCanvas *canvas, const unsigned int frame_time)
    {
        length = rgb_matrix::DrawText(canvas, font,
                                    x + 32, 29 + font.baseline(),
                                    color, NULL,
                                    title, 0);
        
        step += frame_time;
        if(step >= stepTime)
        {
            step = step % stepTime;
            if(--x + length + 32 < 0)
                x = 0;
        }
    }

    void Thumbnail::Reset()
    {
        x = -32;
        step = -firstStep + stepTime;
    }
}
