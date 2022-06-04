#include "paddleSystem.hpp"

namespace Ponglord
{
    PaddleSystem::PaddleSystem()
    {
        if (!font.LoadFont("matrix/fonts/4x6.bdf"))
        {
            fprintf(stderr, "Couldn't load font '%s'\n", "matrix/font/4x6.bdf");
        }
    }
    
    void PaddleSystem::Update(entt::registry &registry, const Slate::Input &input, rgb_matrix::FrameCanvas *canvas)
    {
        // Loop through entities with Paddle, Position and Velocity components
        registry.view<Paddle,Slate::Position,Slate::Velocity>()
        .each([&font=font,&p1_color=p1_color,&p2_color=p2_color,&input,&canvas](auto &pad, auto &pos, auto &vel)
        {
            // Move paddles and render scores
            vel.x = 0;
            if(pad.IsPlayer1())
            {
                vel.x += input.GetButton(0) ? -30.0 : 0;
                vel.x += input.GetButton(1) ? 30.0 : 0;
                
                rgb_matrix::DrawTextInverted(canvas, font,
                                    0, 8,
                                    p1_color, NULL,
                                    std::to_string(pad.score), 0);
            }
            else
            {
                vel.x += input.GetButton(2) ? -20.0 : 0;
                vel.x += input.GetButton(3) ? 20.0 : 0;
                
                rgb_matrix::DrawText(canvas, font,
                                    28, 62,
                                    p2_color, NULL,
                                    std::to_string(pad.score), 0);
            }

            // Limit paddle positions
            pos.x = pos.x < 3.0 ? 3.0 : pos.x;
            pos.x = pos.x > 28.0 ? 28.0 : pos.x;
        });
    }
}
