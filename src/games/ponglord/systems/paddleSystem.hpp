#ifndef PONGLORD_SYSTEMS_PADDLESYSTEM
#define PONGLORD_SYSTEMS_PADDLESYSTEM

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
        ///
        void Update(entt::registry &registry, const Slate::Input &input);
    };
}

#endif