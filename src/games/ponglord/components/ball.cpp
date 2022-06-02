#include "ball.hpp"

namespace Ponglord
{
    Ball::Ball(const unsigned int d, const double s, const double a)
        : start_delay(d), delay(d), start_speed(s), add_speed(a)
    {}

    Ball::Ball(Ball&& b) noexcept
        : start_delay(b.start_delay), start_speed(b.start_speed), add_speed(b.add_speed)
    {
        //this->start_delay = b.start_delay;
        this->delay = b.delay;
        //this->start_speed = b.start_speed;
        //this->add_speed = b.add_speed;
    }
    
    Ball& Ball::operator=(Ball&& p) noexcept
    {
        if (this != &p)
        {
            this->start_delay = b.start_delay;
            this->delay = b.delay;
            this->start_speed = b.start_speed;
            this->add_speed = b.add_speed;
        }

        return *this;
    }
    
    void Ball::Reset(Slate::Position &pos, Slate::Velocity &vel)
    {
        delay = start_delay;
        pos.x = 15.0;
        pos.y = 31.0;
        vel.x = 0.0;
        vel.y = 0.0;
    }
}
