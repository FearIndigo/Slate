#include "main.hpp"

namespace Test
{
    Game::Game()
    {
        // Create thumbnail
        thumbnail("Test game with long title");
    }

    void Game::Run(rgb_matrix::FrameCanvas *canvas, Slate::Input &input, const unsigned int frame_time)
    {
        isRunning = false;
        input.ResetLongPressAll();
    }
}
