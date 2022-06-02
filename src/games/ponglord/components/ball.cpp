#include "ball.hpp"

namespace Ponglord
{
    Ball::Ball(const unsigned int d, const double s, const double a)
        : start_delay(d), delay(d), start_speed(s), add_speed(a)
    {}
    
    Ball::Reset(Slate::Position &pos, Slate::Velocity &vel)
    {
        delay = start_delay;
        pos.x = 15.0;
        pos.y = 31.0;
        vel.x = 0.0;
        vel.y = 0.0;
    }
}
