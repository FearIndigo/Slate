#include "main.hpp"

namespace Test
{
    Game::Game()
        : Slate::BaseGame(),
        thumbnail("Test game with a really long name") {}
    {}

    void Game::Run(rgb_matrix::FrameCanvas *canvas, Slate::Input &input, const unsigned int frame_time)
    {
        IsRunning = false;
        input.ResetLongPressAll();
    }
}
