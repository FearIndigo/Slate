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
        ///
        /// Run game or show thumbnail.
        ///
        bool isRunning;
        
        ///
        /// Main game loop.
        ///
        virtual void Run(rgb_matrix::FrameCanvas *canvas, Slate::Input &input, const unsigned int frame_time) {}
    protected:
        ///
        /// Game thumbnail.
        ///
        Slate::Thumbnail thumbnail;
    };
}

#endif
