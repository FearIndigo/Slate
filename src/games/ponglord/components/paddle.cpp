#include "paddle.hpp"

namespace Ponglord
{
    Paddle::Paddle(const bool p1, const Ponglord::Bounds b, Slate::Position &pos)
        : isPlayer1(p1), bounds(b), position(pos) {}

    bool Paddle::PointInsideBounds(const int x, const int y)
    {
        // Get paddle current position
        const int xPos = position.MatrixX();
        const int yPos = position.MatrixY();
        
        return x <= xPos + bounds.max_x && x >= xPos + bounds.min_x &&
            y <= yPos + bounds.max_y && y >= yPos + bounds.min_y;
    }
}
