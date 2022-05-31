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
        void Display(rgb_matrix::Canvas *canvas)
        {
            rgb_matrix::DrawText(canvas, font,
                                    0, 30 + font.baseline(),
                                    color, NULL,
                                    title, 0);
        }
        
        ///
        /// Run game or show thumbnail.
        ///
        bool isRunning;
        
        ///
        /// Main game loop.
        ///
        virtual void Run(rgb_matrix::FrameCanvas *canvas, Slate::Input input, const unsigned int frame_time) {}
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
        /// The game title
        ///
        const char* title;

        ///
        /// The thumbnail image.
        ///
        //??? thumbnail;
    };
}

#endif
