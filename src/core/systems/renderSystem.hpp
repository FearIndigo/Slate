#ifndef SLATE_SYSTEMS_RENDERSYSTEM
#define SLATE_SYSTEMS_RENDERSYSTEM

#include <entt/entity/registry.hpp>
#include "led-matrix.h"

#include "core/components/position.hpp"
#include "core/components/renderable.hpp"

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