#include "main.hpp"

namespace Test
{
    Game::Game()
        : Slate::BaseGame("TEST GAME 001")
    {}

    void Game::Run(rgb_matrix::FrameCanvas *canvas, Slate::Input &input, const unsigned int frame_time)
    {
        // DEBUG. Set red pixels on if button pressed
        if(input.GetButton(0))
            canvas->SetPixel(0,0,255,0,0);
        if(input.GetButton(1))
            canvas->SetPixel(31,0,255,0,0);
        if(input.GetButton(2))
            canvas->SetPixel(0,63,255,0,0);
        if(input.GetButton(3))
            canvas->SetPixel(31,63,255,0,0);
    }
}
