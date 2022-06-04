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
        step_time = 80;

        // Set how long it takes for the text to initially start scrolling
        first_step = 500;

        // Reset to starting position
        Reset();
    }

    void Thumbnail::Display(rgb_matrix::FrameCanvas *canvas, const rgb_matrix::Font &font, const unsigned int frame_time)
    {
        length = rgb_matrix::DrawText(canvas, font,
                                    x, 62,
                                    color, NULL,
                                    title, 0);

        rgb_matrix::DrawTextInverted(canvas, font,
                                    -x + 32, 8,
                                    color, NULL,
                                    title, 0);
        
        step += frame_time;
        if(step >= step_time)
        {
            step = step % step_time;
            if(--x + length < 0)
                x = 32;
        }
    }

    void Thumbnail::Reset()
    {
        x = 4;
        step = -first_step + step_time;
    }
}
