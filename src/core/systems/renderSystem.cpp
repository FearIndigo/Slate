#include "renderSystem.hpp"

namespace Slate
{
    RenderSystem::RenderSystem() {}
    
    void RenderSystem::Update(entt::registry &registry, rgb_matrix::FrameCanvas *canvas)
    {
        // Loop through entities with Renderable and Position components
        registry.view<Renderable,Position>()
        .each([&canvas](auto &rend, auto &pos)
        {
            // Draw pixels to canvas
            rend.Draw(canvas, pos);
        });
    }
}
