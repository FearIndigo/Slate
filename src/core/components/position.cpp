#include "position.hpp"

namespace Slate
{
    Position::Position(const double init_x, const double init_y)
        : x(init_x), y(init_y) {}

    Position& Position::operator=(Position&& p) noexcept
    {
        if (this != &p)
        {
            this->x = p.x;
            this->y = p.y;
        }

        return *this;
    }
    
    int Position::MatrixX() const
    {
        return (int)(x > 0 ? x + 0.5 : x - 0.5);
    }

    int Position::MatrixY() const
    {
        return (int)(y > 0 ? y + 0.5 : y - 0.5);
    }
}
