#include "main.hpp"

namespace Ponglord
{
    Game::Game()
        : Slate::BaseGame("PONGLORD")
    {
        // Create entities
        const auto ball = registry.create();
        const auto player1 = registry.create();
        const auto player2 = registry.create();

        // Create pixel prefabs
        const std::vector<Slate::Pixel> ball_pixels = {
            {0,0,255,255,255},
        };
        const std::vector<Slate::Pixel> player1_pixels = {
            {-2,0,255,128,0},
            {-1,0,255,128,0},
            {0,0,255,128,0},
            {1,0,255,128,0},
            {2,0,255,128,0}
        };
        const std::vector<Slate::Pixel> player2_pixels = {
            {-2,0,0,128,255},
            {-1,0,0,128,255},
            {0,0,0,128,255},
            {1,0,0,128,255},
            {2,0,0,128,255}
        };

        // Create bounds prefabs
        const Ponglord::Bounds paddle_bounds = {-2,2,0,0};
        
        // Assign component data to entities.
        registry.emplace<Slate::Position>(ball, 15.0, 32.0);
        registry.emplace<Slate::Velocity>(ball, 0.0, 0.0);
        registry.emplace<Slate::Renderable>(ball, ball_pixels);
        registry.emplace<Ponglord::Ball>(ball, 2000, 5.0, 1.0);

        auto &p1Pos = registry.emplace<Slate::Position>(player1, 15.0, 0.0);
        registry.emplace<Slate::Velocity>(player1, 0.0, 0.0);
        registry.emplace<Slate::Renderable>(player1, player1_pixels);
        auto &p1 = registry.emplace<Ponglord::Paddle>(player1, true, 0, paddle_bounds, p1Pos);
        ball_system.p1 = &p1;

        auto &p2Pos = registry.emplace<Slate::Position>(player2, 15.0, 63.0);
        registry.emplace<Slate::Velocity>(player2, 0.0, 0.0);
        registry.emplace<Slate::Renderable>(player2, player2_pixels);
        auto &p2 = registry.emplace<Ponglord::Paddle>(player2, false, 0, paddle_bounds, p2Pos);
        ball_system.p2 = &p2;
    }

    void Game::Run(rgb_matrix::FrameCanvas *canvas, Slate::Input &input, const unsigned int frame_time)
    {
        ball_system.Update(registry, frame_time);
        move_system.Update(registry, frame_time);

        render_system.Update(registry, canvas);
    }
}
