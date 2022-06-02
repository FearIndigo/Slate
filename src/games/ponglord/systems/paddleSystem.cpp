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
                vel.x += input.GetButton(0) ? -20.0 : 0;
                vel.x += input.GetButton(1) ? 20.0 : 0;
            }
            else
            {
                vel.x += input.GetButton(2) ? -20.0 : 0;
                vel.x += input.GetButton(3) ? 20.0 : 0;
            }

            if(pos.MatrixX() <= 2)
            {
                pos.x = 2.0;
            }
            else if (pos.MatrixY() >= 29)
            {
                pos.x = 29.0;
            }
        });
    }
}
