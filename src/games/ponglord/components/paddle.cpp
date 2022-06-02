#include "paddle.hpp"

namespace Ponglord
{
    Paddle::Paddle(const bool p1, const unsigned int s, const Ponglord::Bounds b, Slate::Position &pos)
        : is_player1(p1), score(s), bounds(b), position(&pos) {}

    Paddle::Paddle(Paddle&& p) noexcept
        : is_player1(p.is_player1)
    {
        this->score = p.score;
        this->bounds = p.bounds;
        this->position = p.position;
    }
    
    Paddle& Paddle::operator=(Paddle&& p) noexcept
    {
        if (this != &p)
        {
            this->score = p.score;
            this->bounds = p.bounds;
            this->position = p.position;
        }

        return *this;
    }
    
    bool Paddle::PointInsideBounds(double &angle_change, const int x, const int y) const
    {
        // Get paddle current position
        const int xPos = position->MatrixX();
        const int yPos = position->MatrixY();

        // Change ball dir angle by 10 degrees each pixel away from paddle centre
        angle_change = (x - xPos) * 10.0;
        
        return x <= xPos + bounds.max_x && x >= xPos + bounds.min_x &&
            y <= yPos + bounds.max_y && y >= yPos + bounds.min_y;
    }
}
