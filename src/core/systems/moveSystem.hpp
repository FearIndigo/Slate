#ifndef SLATE_SYSTEMS_MOVESYSTEM
#define SLATE_SYSTEMS_MOVESYSTEM

#include <entt/entity/registry.hpp>

#include "../components/position.hpp"
#include "../components/velocity.hpp"

namespace Slate
{
    class MoveSystem
    {
    public:
        ///
        /// Default constructor.
        ///
        MoveSystem();

        ///
        /// Update entity positions given velocity.
        ///
        /// \param registry The registry to retrieve entities from.
        /// \param frame_time The frame delta time.
        ///
        void Update(entt::registry &registry, const unsigned int frame_time);
    };
}

#endif