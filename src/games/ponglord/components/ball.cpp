#include "ball.hpp"

namespace Ponglord
{
    Ball::Ball(const unsigned int d, const double s, const double a)
        : delay(d), start_delay(d), start_speed(s), add_speed(a)
    {
        srand (time(NULL));
        player1_serve = (rand() % 2) == 0;
        difficulty = 0;
    }

    Ball::Ball(Ball&& b) noexcept
        : start_delay(b.start_delay), start_speed(b.start_speed), add_speed(b.add_speed)
    {
        this->delay = b.delay;
        this->player1_serve = b.player1_serve;
        this->ball_move_angle = b.ball_move_angle;
    }
    
    Ball& Ball::operator=(Ball&& b) noexcept
    {
        if (this != &b)
        {
            this->delay = b.delay;
            this->player1_serve = b.player1_serve;
            this->ball_move_angle = b.ball_move_angle;
        }

        return *this;
    }
    
    void Ball::Reset(Slate::Position &pos, Slate::Velocity &vel)
    {
        difficulty = 0;
        delay = start_delay;
        pos.x = 15.0;
        pos.y = 31.0;
        vel.x = 0.0;
        vel.y = 0.0;
    }

    void Ball::Serve(Slate::Velocity &vel)
    {
        ball_move_angle = ((rand() % 900) - 450) / 10.0; // -45.0 to 45.0 degrees
        const double x_dir = std::sin(ball_move_angle * 3.14159265359 / 180.0);
        const double y_dir = std::cos(ball_move_angle * 3.14159265359 / 180.0);
        
        vel.x = start_speed * x_dir;
        vel.y = (player1_serve ? 1.0 : -1.0) * start_speed * y_dir;
    }

    void Ball::IncreaseDificulty(const double angle_change, Slate::Velocity &vel)
    {
        difficulty++;
        const double new_speed = start_speed + (add_speed * difficulty);
        
        ball_move_angle = std::clamp(ball_move_angle + angle_change, -60.0, 60.0); // -60.0 to 60.0 degrees
        const double x_dir = std::sin(ball_move_angle * 3.14159265359 / 180.0);
        const double y_dir = std::cos(ball_move_angle * 3.14159265359 / 180.0);
        
        vel.x = new_speed * x_dir;
        vel.y = ((vel.y > 0) - (vel.y < 0)) * new_speed * std::abs(y_dir);
    }
}
