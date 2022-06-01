#include "main.hpp"

namespace Ponglord
{
    Game::Game()
        : Slate::BaseGame("PONGLORD")
    {
        // Create entities
        const auto test = registry.create();

        // Assign component data to entities.
        registry.emplace<Slate::Position>(test, 15.0, 31.0);
        const std::vector<Slate::Pixel> test_pixels = {
            {0,0,255,255,255},
            {1,0,0,255,255},
            {-1,0,255,255,0}
        };
        registry.emplace<Slate::Renderable>(test, test_pixels);
    }

    void Game::Run(rgb_matrix::FrameCanvas *canvas, Slate::Input &input, const unsigned int frame_time)
    {
        move_system.Update(registry, frame_time);

        render_system.Update(registry, canvas);
    }
}
