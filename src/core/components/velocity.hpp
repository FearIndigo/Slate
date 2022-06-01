#ifndef SLATE_COMPONENTS_VELOCITY
#define SLATE_COMPONENTS_VELOCITY

namespace Slate
{
    class Velocity
    {
    public:
        ///
        /// Constructor.
        ///
        /// \param x The starting x velocity.
        /// \param y The starting y velocity.
        ///
        Velocity(const double init_x, const double init_y);
        
        ///
        /// x velocity in pixels per second.
        ///
        double x;

        ///
        /// y velocity in pixels per second.
        ///
        double y;
    };
}

#endif