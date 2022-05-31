#ifndef SLATE_BASE_BASEGAME
#define SLATE_BASE_BASEGAME

#include "led-matrix.h"
#include "graphics.h"
#include "../input/input.hpp"

namespace Slate
{
    class BaseGame
    {
    public:
        ///
        /// Display the games thumbnail.
        ///
        void Display(rgb_matrix::Canvas *canvas, const unsigned int frame_time)
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
        
        ///
        /// Run game or show thumbnail.
        ///
        bool isRunning;
        
        ///
        /// Whether to display the long press visuals when running.
        ///
        bool showLongPress;
        
        ///
        /// Main game loop.
        ///
        virtual void Run(rgb_matrix::FrameCanvas *canvas, Slate::Input &input, const unsigned int frame_time) {}
    protected:
        ///
        /// Font used for display.
        ///
        rgb_matrix::Font font;

        ///
        /// Colour used for display.
        ///
        rgb_matrix::Color color;
        
        ///
        /// The game title.
        ///
        const char* title;
        
        ///
        /// How many x axis pixels the title takes up.
        ///
        int length;
        
        ///
        /// Text display x value.
        ///
        int x;
        
        ///
        /// How long the current display frame has been displayed for.
        ///
        int step;
                
        ///
        /// The thumbnail image.
        ///
        //??? thumbnail;
    };
}

#endif
