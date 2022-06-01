﻿#include "moveSystem.hpp"

namespace Slate
{
    void MoveSystem::Update(entt::registry &registry, const unsigned int frame_time)
    {
        // Loop through entities with Position and Velocity components
        registry.view<Position,Velocity>()
        .each([](auto &pos, auto &vel)
        {
            // Update entity position given its velocity
            pos.x += vel.x * frame_time;
            pos.y += vel.y * frame_time;
        });
    }
}