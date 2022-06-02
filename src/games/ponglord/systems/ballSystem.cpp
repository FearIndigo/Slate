﻿#include "ballSystem.hpp"

namespace Ponglord
{
    BallSystem::BallSystem() {}
    
    void BallSystem::Update(entt::registry &registry, const unsigned int frame_time)
    {
        // Loop through entities with Ball, Position and Velocity components
        registry.view<Ball,Slate::Position,Slate::Velocity>()
        .each([&p1,&p2,&frame_time](auto &ball, auto &pos, auto &vel)
        {
            // Wait till delay time has finished before moving ball.
            if(ball.delay > 0)
            {
                delay -= frame_time;
                break;
            }
            // Start ball moving after delay time has finished
            else if (vel.x == 0.0 && vel.y == 0.0)
            {
                vel.x = ball.start_speed / 2.0;
                vel.y = ball.start_speed / 2.0;
            }

            const int x = pos.MatrixX();
            const int y = pos.MatrixY();
            
            // If the ball has moved off to the side of the playing field
            if((x < 0 && vel.x < 0.0) ||
                (x > 31 && vel.x > 0.0))
            {
                vel.x *= -1.0;
            }

            // If the ball has collided with a paddle
            if((y < 0 && p1.PointInsideBounds(x,y)) ||
                (y > 0 && p2.PointInsideBounds(x,y))
            {
                vel.y *= -1.0;
            }
            // If the ball has reach player 1's goals
            else if(y < 0)
            {
                p2.score++;
                ball.Reset(pos);
            }
            // If the ball has reach player 2's goals
            else if (y > 63)
            {
                p1.score++;
                ball.Reset(pos);
            }
        });
    }
}