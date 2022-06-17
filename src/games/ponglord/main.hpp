#include <entt/entity/registry.hpp>

#include "core/baseGame.hpp"
#include "systems/ballSystem.hpp"
#include "systems/paddleSystem.hpp"
#include "core/systems/moveSystem.hpp"
#include "core/systems/renderSystem.hpp"

namespace Ponglord
{
    class Game : public Slate::BaseGame
    {
    public:
        ///
        /// Main constructor.
        ///                                               
        Game();

        ///
        /// Reset the game.
        ///
        void Reset();
        
        ///
        /// The main game loop.
        ///
        void Run(rgb_matrix::FrameCanvas *canvas, Slate::Input &input, const rgb_matrix::Font &font, const unsigned int frame_time);
    private:
        ///
        /// The default entt registry to hold and manage our entities.
        ///
        entt::registry registry;

        ///
        /// The ball system.
        ///
        Ponglord::BallSystem ball_system;

        ///
        /// The paddle system.
        ///
        Ponglord::PaddleSystem paddle_system;
        
        ///
        /// The movement system.
        ///
        Slate::MoveSystem move_system;

        ///
        /// The Render system.
        ///
        Slate::RenderSystem render_system;
    };
}