#include "main.hpp"

namespace Test
{
    Game::Game()
        : thumbnail("Test game with a very long title") {}
    {}

    void Game::Run(rgb_matrix::FrameCanvas *canvas, Slate::Input &input, const unsigned int frame_time)
    {
        IsRunning = false;
        input.ResetLongPressAll();
    }
}
