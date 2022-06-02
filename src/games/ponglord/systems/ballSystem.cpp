#include "ballSystem.hpp"

namespace Ponglord
{
    BallSystem::BallSystem() {}
    
    void BallSystem::Update(entt::registry &registry, const unsigned int frame_time)
    {
        // Loop through entities with Ball, Position and Velocity components
        registry.view<Ball,Slate::Position,Slate::Velocity>()
        .each([&p1=p1,&p2=p2,&frame_time](auto &ball, auto &pos, auto &vel)
        {
            // Wait till delay time has finished before moving ball.
            if(ball.delay > 0)
            {
                ball.delay -= frame_time;
                return;
            }
            // Start ball moving after delay time has finished
            else if (vel.x == 0.0 && vel.y == 0.0)
            {
                ball.Serve(vel);
            }

            const int x = pos.MatrixX();
            const int y = pos.MatrixY();
            
            // If the ball has hit the side of the playing field
            if((x <= 0 && vel.x < 0.0) ||
                (x >= 31 && vel.x > 0.0))
            {
                vel.x *= -1.0;
            }

            // If the ball has collided with a paddle
            if((p1->PointInsideBounds(x,y) && vel.y < 0) ||
                (p2->PointInsideBounds(x,y) && vel.y > 0))
            {
                vel.y += (vel.y > 0) - (vel.y < 0) * ball.add_speed;
                vel.y *= -1.0;
            }
            // If the ball has reach player 1's goals
            else if(y < 0)
            {
                p2->score++;
                ball.player1_serve = true;
                ball.Reset(pos,vel);
            }
            // If the ball has reach player 2's goals
            else if (y > 63)
            {
                p1->score++;
                ball.player1_serve = false;
                ball.Reset(pos,vel);
            }
        });
    }
}
