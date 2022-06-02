#include "ball.hpp"
#include <iostream>

namespace Ponglord
{
    Ball::Ball(const unsigned int d, const double s, const double a)
        : delay(d), start_delay(d), start_speed(s), add_speed(a)
    {
        srand (time(NULL));
        player1_serve = (rand() % 2) == 0;
    }

    Ball::Ball(Ball&& b) noexcept
        : start_delay(b.start_delay), start_speed(b.start_speed), add_speed(b.add_speed)
    {
        this->delay = b.delay;
        this->player1_serve = b.player1_serve;
        this->x_dir = b.x_dir;
        this->y_dir = b.y_dir;
    }
    
    Ball& Ball::operator=(Ball&& b) noexcept
    {
        if (this != &b)
        {
            this->delay = b.delay;
            this->player1_serve = b.player1_serve;
            this->x_dir = b.x_dir;
            this->y_dir = b.y_dir;
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

    void Ball::Serve(Slate::Velocity &vel)
    {
        const int deg = (rand() % 60) - 30; // -30 to 30 degrees
        std::cout << deg;
        std::cout << "\n";
        x_dir = std::cos(deg * 180.0/3.14159265);
        y_dir = std::sin(deg * 180.0/3.14159265);
        vel.x = start_speed * x_dir;
        vel.y = (player1_serve ? 1.0 : -1.0) * start_speed * y_dir;
    }

    void Ball::IncreaseDificulty(Slate::Velocity &vel)
    {
        vel.x += (vel.x > 0) - (vel.x < 0) * add_speed * std::abs(x_dir);
        vel.y += (vel.y > 0) - (vel.y < 0) * add_speed * std::abs(y_dir);
    }
}
