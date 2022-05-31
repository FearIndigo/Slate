#include "main.hpp"

namespace Test
{
    Game::Game()
        : Slate::BaseGame("TEST GAME 001")
    {}

    void Game::Run(rgb_matrix::FrameCanvas *canvas, Slate::Input &input, const unsigned int frame_time)
    {
        IsRunning = false;
        input.ResetLongPressAll();
    }
}
