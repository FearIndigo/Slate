#include "main.hpp"

namespace Ponglord
{
    Game::Game()
        : Slate::BaseGame("PONGLORD")
    {
        // Create entities
        const auto test1 = registry.create();
        const auto test2 = registry.create();
        const auto test3 = registry.create();
        const auto test4 = registry.create();

        // Create pixel prefabs
        const std::vector<Slate::Pixel> test_pixels = {
            {0,0,255,255,255},
            {1,0,0,255,255},
            {-1,0,255,255,0},
            {-1,2,0,0,255}
        };
        
        // Assign component data to entities.
        registry.emplace<Slate::Position>(test1, 15.0, 32.0);
        registry.emplace<Slate::Velocity>(test1, 0.0, 1.0);
        registry.emplace<Slate::Renderable>(test1, test_pixels);
        registry.emplace<Slate::Position>(test2, 16.0, 31.0);
        registry.emplace<Slate::Velocity>(test2, 1.0, 0.0);
        registry.emplace<Slate::Renderable>(test2, test_pixels);
        registry.emplace<Slate::Position>(test3, 15.0, 30.0);
        registry.emplace<Slate::Velocity>(test3, 0.0, -1.0);
        registry.emplace<Slate::Renderable>(test3, test_pixels);
        registry.emplace<Slate::Position>(test4, 14.0, 31.0);
        registry.emplace<Slate::Velocity>(test4, -1.0, 0.0);
        registry.emplace<Slate::Renderable>(test4, test_pixels);
    }

    void Game::Run(rgb_matrix::FrameCanvas *canvas, Slate::Input &input, const unsigned int frame_time)
    {
        move_system.Update(registry, frame_time);

        render_system.Update(registry, canvas);
    }
}
