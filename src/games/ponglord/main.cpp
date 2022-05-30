#include "main.hpp"

namespace Ponglord
{
    Game::Game()
        : Slate::BaseGame("Ponglord", rgb_matrix::Color(128,128,128)) {}
    {
        // Load font
        if (!font.LoadFont("../../../matrix/fonts/6x12.bdf")) {
            fprintf(stderr, "Couldn't load font '%s'\n", "../../../matrix/fonts/6x12.bdf");
        }
    }

    void Game::Run()
    {
        
    }
}
