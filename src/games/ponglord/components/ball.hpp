#ifndef PONGLORD_COMPONENTS_BALL
#define PONGLORD_COMPONENTS_BALL

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
        
        ///
        /// Reset the ball to the starting state for each round.
        ///
        /// \param pos The ball position.
        /// \param vel The ball velocity.
        ///
        void Reset(Slate::Position &pos, Slate::Velocity &vel);
        
        ///
        /// How long to delay the ball from moving at the start of each round.
        ///
        const unsigned int start_delay;

        ///
        /// How much longer the ball has left before it starts moving at the start of the round.
        ///
        unsigned int delay;

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