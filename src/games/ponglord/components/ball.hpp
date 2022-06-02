#ifndef PONGLORD_COMPONENTS_BALL
#define PONGLORD_COMPONENTS_BALL

#include <stdlib.h>
#include <time.h>
#include <cmath>
#include <algorithm>

#include "core/components/position.hpp"
#include "core/components/velocity.hpp"

namespace Ponglord
{
    class Ball
    {
    public:
        ///
        /// Constructor.
        ///
        /// \param d How long to delay the ball from moving at the start of each round.
        /// \param s The starting speed of the ball.
        /// \param a How much speed to add each time the ball hits a paddle.
        ///
        Ball(const unsigned int d, const double s, const double a);

        Ball(Ball&&) noexcept;
        
        Ball& operator=(Ball&&) noexcept;
        
        ///
        /// Reset the ball to the starting state for each round.
        ///
        /// \param pos The ball position.
        /// \param vel The ball velocity.
        ///
        void Reset(Slate::Position &pos, Slate::Velocity &vel);

        ///
        /// Serve the ball at the start of the round
        ///
        /// \param vel The ball velocity.
        ///
        void Serve(Slate::Velocity &vel);

        ///
        /// Add speed to the ball after hitting the paddle.
        ///
        /// \param The angle to change the move dir by.
        /// \param The ball velocity.
        ///
        void IncreaseDificulty(const double angle_change, Slate::Velocity &vel);

        ///
        /// How much longer the ball has left before it starts moving at the start of the round.
        ///
        int delay;

        ///
        /// Should player 1 serve the ball
        ///
        bool player1_serve;

        ///
        /// The direction the ball is moving
        ///
        double ball_move_angle;
    private:
        ///
        /// How long to delay the ball from moving at the start of each round.
        ///
        const unsigned int start_delay;
        
        ///
        /// The starting speed of the ball.
        ///
        const double start_speed;

        ///
        /// How much speed to add each time the ball hits a paddle.
        ///
        const double add_speed;
    };
}

#endif