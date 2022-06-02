#ifndef PONGLORD_COMPONENTS_PADDLE
#define PONGLORD_COMPONENTS_PADDLE

#include "core/components/position.hpp"

namespace Ponglord
{
    struct Bounds
    {
        int min_x;
        int max_x;
        int min_y;
        int max_y;
    };
    
    class Paddle
    {
    public:
        ///
        /// Constructor.
        ///
        /// \param p1 Does the paddle belong to player 1.
        /// \param s The starting score for this paddle.
        /// \param b The collisions bounds of the paddle relative to its position.
        /// \param pos The paddle's position component.
        ///
        Paddle(const bool p1, const unsigned int s, const Ponglord::Bounds b, Slate::Position &pos);

        Paddle(Paddle&&) noexcept;
        
        Paddle& operator=(Paddle&&) noexcept;

        ///
        /// The score for this paddle.
        ///
        unsigned int score;
        
        ///
        /// Test if a point is inside the paddle collision bounds;
        ///
        /// \param x Point x position.
        /// \param y Point y position.
        ///
        bool PointInsideBounds(const int x, const int y) const;
    private:
        ///
        /// Does the paddle belong to player 1.
        ///
        const bool is_player1;
        
        ///
        /// The collision bounds of the paddle relative to the paddle's position.
        ///
        Ponglord::Bounds bounds;

        ///
        /// The paddle's position component.
        ///
        Slate::Position *position;
    };
}

#endif