#include "main.hpp"

namespace Ponglord
{
    Game::Game()
    {
        // Set game title
        title = "Ponglord";

        // Load font
        if (!font.LoadFont("../../../matrix/fonts/6x12.bdf")) {
            fprintf(stderr, "Couldn't load font '%s'\n", "../../../matrix/fonts/6x12.bdf");
        }

        // Set font color
        color = (rgb_matrix::Color){.r = 128, .g = 128, .b = 128};
    }

    void Game::Display(rgb_matrix::Canvas *canvas)
    {
        rgb_matrix::DrawText(canvas, font,
                                        0, 30 + font.baseline(),
                                        color, NULL,
                                        title, 0);
    }

    void Game::Run()
    {
        
    }
}
