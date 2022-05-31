#include <stdexcept>
#include <entt/entt.hpp>

#include "../../core/base/baseGame.hpp"

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
        void Run(rgb_matrix::FrameCanvas *canvas, Slate::Input& input, const unsigned int frame_time);
    private:
        ///
        /// Recieve and process game events.
        ///
        void events();

        ///
        /// Process game data.
        ///
        void update();

        ///
        /// Render everything to the window.
        ///
        void render();

        ///
        /// The default entt registry to hold and manage our entities.
        ///
        entt::registry m_registry;

        ///
        /// Default event dispatcher.
        ///
        entt::dispatcher m_dispatcher;

        ///
        /// The AI system.
        ///
        //AISystem m_ai_system;

        ///
        /// The collision system.
        ///
        //CollisionSystem m_collision_system;

        ///
        /// Holds collideables for collision system.
        ///
        //CollisionHolder m_collideables;

        ///
        /// The movement system.
        ///
        //MoveSystem m_move_system;

        ///
        /// The Render system.
        ///
        //RenderSystem m_render_system;
    };
}