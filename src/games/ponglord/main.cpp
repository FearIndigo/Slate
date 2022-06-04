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
            {-3,0,255,128,0},
            {-2,0,255,128,0},
            {-1,0,255,128,0},
            {0,0,255,128,0},
            {1,0,255,128,0},
            {2,0,255,128,0},
            {3,0,255,128,0}
        };
        const std::vector<Slate::Pixel> player2_pixels = {
            {-3,0,0,128,255},
            {-2,0,0,128,255},
            {-1,0,0,128,255},
            {0,0,0,128,255},
            {1,0,0,128,255},
            {2,0,0,128,255},
            {3,0,0,128,255}
        };

        // Create bounds prefabs
        const Ponglord::Bounds paddle_bounds = {-3,3,0,0};
        
        // Assign component data to entities.
        registry.emplace<Slate::Position>(ball, 15.0, 32.0);
        registry.emplace<Slate::Velocity>(ball, 0.0, 0.0);
        registry.emplace<Slate::Renderable>(ball, ball_pixels);
        registry.emplace<Ponglord::Ball>(ball, 2000, 20.0, 5.0);

        auto &p1Pos = registry.emplace<Slate::Position>(player1, 15.0, 1.0);
        registry.emplace<Slate::Velocity>(player1, 0.0, 0.0);
        registry.emplace<Slate::Renderable>(player1, player1_pixels);
        auto &p1 = registry.emplace<Ponglord::Paddle>(player1, true, paddle_bounds, p1Pos);
        ball_system.p1 = &p1;
        paddle_system.p1_color = {128,64,0};

        auto &p2Pos = registry.emplace<Slate::Position>(player2, 15.0, 62.0);
        registry.emplace<Slate::Velocity>(player2, 0.0, 0.0);
        registry.emplace<Slate::Renderable>(player2, player2_pixels);
        auto &p2 = registry.emplace<Ponglord::Paddle>(player2, false, paddle_bounds, p2Pos);
        ball_system.p2 = &p2;
        paddle_system.p2_color = {0,64,128};
    }

    void Game::Run(rgb_matrix::FrameCanvas *canvas, Slate::Input &input, const rgb_matrix::Font font, const unsigned int frame_time)
    {
        ball_system.Update(registry, frame_time);
        paddle_system.Update(registry, input, canvas, font);
        move_system.Update(registry, frame_time);

        render_system.Update(registry, canvas);
    }
}
