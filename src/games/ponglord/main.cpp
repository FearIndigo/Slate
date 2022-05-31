#include "main.hpp"

namespace Ponglord
{
    Game::Game()
    {
        isRunning = false;
        title = "Ponglord";
        color = {128,128,128};

        // Load font
        if (!font.LoadFont("matrix/fonts/4x6.bdf")) {
            fprintf(stderr, "Couldn't load font '%s'\n", "matrix/font/4x6.bdf");
            throw std::invalid_argument("Could load font use for Ponglord.");
        }
    }

    void Game::Run(rgb_matrix::Canvas *canvas, Slate::Input input, const unsigned int frame_time)
    {
        // DEBUG. Set pixels on/off based on input values
        canvas->SetPixel(0,0,0,0,input.GetButton(0)?255:0);
        canvas->SetPixel(31,0,0,0,input.GetButton(1)?255:0);
        canvas->SetPixel(0,63,0,0,input.GetButton(2)?255:0);
        canvas->SetPixel(31,63,0,0,input.GetButton(3)?255:0);
    }
}
