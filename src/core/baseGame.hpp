#ifndef SLATE_BASE_BASEGAME
#define SLATE_BASE_BASEGAME

#include <stdexcept>
#include "led-matrix.h"
#include "input.hpp"
#include "thumbnail.hpp"

namespace Slate
{
    class BaseGame
    {
    public:
        BaseGame(const char* title) : IsRunning(false), thumbnail(title) {}
        ///
        /// Run game or show thumbnail.
        ///
        bool IsRunning;
        
        ///
        /// Main game loop.
        ///
        virtual void Run(rgb_matrix::FrameCanvas *canvas, Slate::Input &input, const unsigned int frame_time) {}

        ///
        /// Display the game thumbnail.
        ///
        void DisplayThumbnail(rgb_matrix::FrameCanvas *canvas, const unsigned int frame_time)
        {
            thumbnail.Display(canvas, frame_time);
        }
    private:
        ///
        /// Game thumbnail.
        ///
        Slate::Thumbnail thumbnail;
    };
}

#endif
