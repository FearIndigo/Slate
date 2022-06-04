#ifndef PONGLORD_SYSTEMS_PADDLESYSTEM
#define PONGLORD_SYSTEMS_PADDLESYSTEM

#include <string>
#include "led-matrix.h"
#include "graphics.h"
#include <entt/entity/registry.hpp>

#include "core/components/position.hpp"
#include "core/components/velocity.hpp"
#include "../components/paddle.hpp"
#include "core/input.hpp"

namespace Ponglord
{
    class PaddleSystem
    {
    public:
        ///
        /// Default constructor.
        ///
        PaddleSystem();

        ///
        /// Detect collisions with walls and paddles.
        ///
        /// \param registry The registry to retrieve entities from.
        /// \param input The player inputs.
        /// \param canvas The frame canvas to draw scores to.
        /// \param font Font used to display score.
        ///
        void Update(entt::registry &registry, const Slate::Input &input, rgb_matrix::FrameCanvas *canvas, const rgb_matrix::Font font);

        ///
        /// Player 1 score colour.
        ///
        rgb_matrix::Color p1_color;

        ///
        /// Player 2 score colour.
        ///
        rgb_matrix::Color p2_color;
    };
}

#endif