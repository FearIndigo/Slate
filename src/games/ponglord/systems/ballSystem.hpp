#ifndef PONGLORD_SYSTEMS_BALLSYSTEM
#define PONGLORD_SYSTEMS_BALLSYSTEM

#include <entt/entity/registry.hpp>

#include "core/components/position.hpp"
#include "core/components/velocity.hpp"
#include "components/ball.hpp"
#include "components/paddle.hpp"

namespace Ponglord
{
    class BallSystem
    {
    public:
        ///
        /// Default constructor.
        ///
        BallSystem();

        ///
        /// Detect collisions with walls and paddles.
        ///
        /// \param registry The registry to retrieve entities from.
        /// \param frame_time The frame delta time.
        ///
        void Update(entt::registry &registry, const unsigned int frame_time);

        ///
        /// Player 1's paddle.
        ///
        Ponglord::Paddle &p1;

        ///
        /// Player 2's paddle.
        ///
        Ponglord::Paddle &p2;
    };
}

#endif