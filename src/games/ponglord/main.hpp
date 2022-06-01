#include <entt/entt.hpp>

#include "core/baseGame.hpp"
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
        /// The main game loop.
        ///
        void Run(rgb_matrix::FrameCanvas *canvas, Slate::Input &input, const unsigned int frame_time);
    private:
        ///
        /// The default entt registry to hold and manage our entities.
        ///
        entt::registry registry;

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