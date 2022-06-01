#ifndef SLATE_SYSTEMS_RENDERSYSTEM
#define SLATE_SYSTEMS_RENDERSYSTEM

#include <entt/registry.hpp>
#include "led-matrix.h"

#include "../components/position.hpp"
#include "../components/renderable.hpp"

namespace Slate
{
    class RenderSystem
    {
    public:
        ///
        /// Default constructor.
        ///
        RenderSystem();

        ///
        /// Update entity positions given velocity.
        ///
        /// \param registry The registry to retrieve entities from.
        /// \param canvas The frame canvas to draw pixels to.
        ///
        void Update(entt::registry &registry, rgb_matrix::FrameCanvas *canvas);
    };
}

#endif