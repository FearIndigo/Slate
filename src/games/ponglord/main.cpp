#include "main.hpp"

namespace Ponglord
{
    Game::Game()
    {
        title = "Ponglord";
        color = {128,128,128};

        // Load font
        if (!font.LoadFont("matrix/fonts/4x6.bdf")) {
            fprintf(stderr, "Couldn't load font '%s'\n", "matrix/font/4x6.bdf");
        }
    }

    void Game::Run()
    {
        
    }
}
