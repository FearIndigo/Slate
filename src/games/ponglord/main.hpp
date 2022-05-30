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
        void Run();
    private:
        ///
        /// Recieve and process game events.
        ///
        void events();

        ///
        /// Process game data.
        ///
        /// \param time The DeltaTime or similar from fixed-timestep loop.
        ///
        void update(const double time);

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