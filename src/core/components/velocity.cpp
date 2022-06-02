#include "velocity.hpp"

namespace Slate
{
    Velocity::Velocity(const double init_x, const double init_y)
        : x(init_x), y(init_y) {}

    Velocity::Velocity(Velocity&& v) noexcept
    {
        this->x = v.x;
        this->y = v.y;
    }
    
    Velocity& Velocity::operator=(Velocity&& v) noexcept
    {
        if (this != &v)
        {
            this->x = v.x;
            this->y = v.y;
        }

        return *this;
    }
}
