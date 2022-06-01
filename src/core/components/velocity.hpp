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
        /// x velocity.
        ///
        double x;

        ///
        /// y velocity.
        ///
        double y;
    };
}

#endif