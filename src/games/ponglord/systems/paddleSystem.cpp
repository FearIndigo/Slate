#include "paddleSystem.hpp"

namespace Ponglord
{
    BallSystem::BallSystem() {}
    
    void BallSystem::Update(entt::registry &registry, const Slate::Input &input)
    {
        // Loop through entities with Paddle, Position and Velocity components
        registry.view<Paddle,Slate::Position,Slate::Velocity>()
        .each([&input](auto &pad, auto &pos, auto &vel)
        {
            vel.x = 0;
            if(pad.is_player1)
            {
                if(input.GetButton(0))
                {
                    vel.x += -3.0;
                }
                
                if(input.GetButton(1))
                {
                    vel.x += 3.0;
                }
            }
            else
            {
                if(input.GetButton(2))
                {
                    vel.x += -3.0;
                }
                
                if(input.GetButton(3))
                {
                    vel.x += 3.0;
                }
            }
        });
    }
}
