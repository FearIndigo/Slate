#include "main.hpp"

namespace Ponglord
{
    Game::Game()
        : Slate::BaseGame("PONGLORD")
    {}

    void Game::Run(rgb_matrix::FrameCanvas *canvas, Slate::Input &input, const unsigned int frame_time)
    {
        // DEBUG. Set blue pixels on if button pressed
        if(input.GetButton(0))
            canvas->SetPixel(0,0,0,0,255);
        if(input.GetButton(1))
            canvas->SetPixel(31,0,0,0,255);
        if(input.GetButton(2))
            canvas->SetPixel(0,63,255,0,0);
        if(input.GetButton(3))
            canvas->SetPixel(31,63,255,0,0);
    }
}
