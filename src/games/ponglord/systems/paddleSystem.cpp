#include "paddleSystem.hpp"

namespace Ponglord
{
    PaddleSystem::PaddleSystem() {}
    
    void PaddleSystem::Update(entt::registry &registry, const Slate::Input &input)
    {
        // Loop through entities with Paddle, Position and Velocity components
        registry.view<Paddle,Slate::Position,Slate::Velocity>()
        .each([&input](auto &pad, auto &pos, auto &vel)
        {
            vel.x = 0;
            if(pad.IsPlayer1())
            {
                vel.x += input.GetButton(0) ? -10.0 : 0;
                vel.x += input.GetButton(1) ? 10.0 : 0;
            }
            else
            {
                vel.x += input.GetButton(2) ? -10.0 : 0;
                vel.x += input.GetButton(3) ? 10.0 : 0;
            }
        });
    }
}
