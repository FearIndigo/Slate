#include "paddleSystem.hpp"

namespace Ponglord
{
    PaddleSystem::PaddleSystem() {}
    
    void PaddleSystem::Update(entt::registry &registry, const Slate::Input &input, rgb_matrix::FrameCanvas *canvas, const rgb_matrix::Font &font)
    {
        // Loop through entities with Paddle, Position and Velocity components
        registry.view<Paddle,Slate::Position,Slate::Velocity>()
        .each([&p1_color=p1_color,&p2_color=p2_color,&input,&canvas,&font](auto &pad, auto &pos, auto &vel)
        {
            // Move paddles and render scores
            vel.x = 0;
            if(pad.IsPlayer1())
            {
                vel.x += input.GetButton(0) ? -35.0 : 0;
                vel.x += input.GetButton(1) ? 35.0 : 0;
                
                rgb_matrix::DrawTextInverted(canvas, font,
                                    32, 31,
                                    p1_color, NULL,
                                    std::to_string(pad.score).c_str(), 0);
            }
            else
            {
                vel.x += input.GetButton(2) ? -35.0 : 0;
                vel.x += input.GetButton(3) ? 35.0 : 0;
                
                rgb_matrix::DrawText(canvas, font,
                                    1, 38,
                                    p2_color, NULL,
                                    std::to_string(pad.score).c_str(), 0);
            }

            // Limit paddle positions
            pos.x = pos.x < 3.0 ? 3.0 : pos.x;
            pos.x = pos.x > 28.0 ? 28.0 : pos.x;
        });
    }
}
