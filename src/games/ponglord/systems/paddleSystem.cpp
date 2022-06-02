#include "paddleSystem.hpp"

namespace Ponglord
{
    PaddleSystem::PaddleSystem() {}
    
    void PaddleSystem::Update(entt::registry &registry, const Slate::Input &input, rgb_matrix::FrameCanvas *canvas)
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
                for (int i=0; i < pad.score; ++i)
                {
                    canvas->SetPixel(i,0,32,32,32);
                }
            }
            else
            {
                vel.x += input.GetButton(2) ? -20.0 : 0;
                vel.x += input.GetButton(3) ? 20.0 : 0;
                for (int i=0; i < pad.score; ++i)
                {
                    canvas->SetPixel(32-i,63,32,32,32);
                }
            }
            
            pos.x = pos.x < 3.0 ? 3.0 : pos.x;
            pos.x = pos.x > 28.0 ? 28.0 : pos.x;
        });
    }
}
