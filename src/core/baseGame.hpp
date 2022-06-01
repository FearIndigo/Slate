﻿#ifndef SLATE_BASEGAME
#define SLATE_BASEGAME

#include <stdexcept>
#include "led-matrix.h"
#include "input.hpp"
#include "thumbnail.hpp"

namespace Slate
{
    class BaseGame
    {
    public:
        BaseGame(const char* title) : thumbnail(new Slate::Thumbnail(title)) {}
        ///
        /// Main game loop.
        ///
        virtual void Run(rgb_matrix::FrameCanvas *canvas, Slate::Input &input, const unsigned int frame_time) {}
        
        ///
        /// Game thumbnail.
        ///
        Slate::Thumbnail *thumbnail;
    private:
    };
}

#endif
