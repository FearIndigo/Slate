#include "main.hpp"

namespace Ponglord
{
    Game::Game()
        : thumbnail("Ponglord") {}
    {}

    void Game::Run(rgb_matrix::FrameCanvas *canvas, Slate::Input &input, const unsigned int frame_time)
    {
        // Return to main menu when all buttons have been long pressed
        if(input.GetButtonLongPress(0) && input.GetButtonLongPress(1) &&
            input.GetButtonLongPress(2) && input.GetButtonLongPress(3))
        {
            isRunning = false;
            input.ResetLongPressAll();
        }
        
        // DEBUG. Set pixels on/off based on input values
        if(input.GetButton(0))
            canvas->SetPixel(0,0,0,0,255);
        if(input.GetButton(1))
            canvas->SetPixel(31,0,0,0,255);
        if(input.GetButton(2))
            canvas->SetPixel(0,63,0,0,255);
        if(input.GetButton(3))
            canvas->SetPixel(31,63,0,0,255);
    }
}
