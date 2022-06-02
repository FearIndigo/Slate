#ifndef PONGLORD_COMPONENTS_PADDLE
#define PONGLORD_COMPONENTS_PADDLE

namespace Ponglord
{
    struct Bounds
    {
        const int min_x;
        const int max_x;
        const int min_y;
        const int max_y;
    };
    
    class Paddle
    {
    public:
        ///
        /// Constructor.
        ///
        /// \param p1 Does the paddle belong to player 1.
        /// \param b The collisions bounds of the paddle relative to its position.
        /// \param pos The paddle's position component.
        ///
        Paddle(const bool p1, const Ponglord::Bounds b, Slate::Position &pos);

        Paddle(Paddle&&) noexcept;
        
        Paddle& operator=(Paddle&&) noexcept;
        
        ///
        /// Does the paddle belong to player 1.
        ///
        const bool isPlayer1;

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
        bool PointInsideBounds(const int x, const int y);
    private:
        ///
        /// The collision bounds of the paddle relative to the paddle's position.
        ///
        Ponglord::Bounds bounds;

        ///
        /// The paddle's position component.
        ///
        Slate::Position position;
    };
}

#endif