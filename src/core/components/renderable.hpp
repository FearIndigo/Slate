﻿#ifndef SLATE_COMPONENTS_RENDERABLE
#define SLATE_COMPONENTS_RENDERABLE

#include <stdint.h>
#include "position.hpp"

namespace Slate
{
    struct Pixel
    {
        int rel_x;
        int rel_y;
        uint8_t r;
        uint8_t g;
        uint8_t b;
    };
    
    class Renderable
    {
    public:
        ///
        /// Constructor.
        ///
        /// \param p The pixels to draw with positions relative to entity position.
        ///
        Renderable(const Pixel p*);

        ///
        /// The pixels to draw relative to the entity position.
        ///
        Pixel pixels*;

        ///
        /// Draw the pixels to the canvas.
        ///
        /// \param canvas The frame canvas to draw to.
        /// \param position The position of the entity.
        ///
        void Draw(rgb_matrix::FrameCanvas *canvas, const Slate::Position position);
    };
}

#endif