﻿#ifndef SLATE_COMPONENTS_POSITION
#define SLATE_COMPONENTS_POSITION

namespace Slate
{
    class Position
    {
    public:
        ///
        /// Constructor.
        ///
        /// \param init_x The starting x position.
        /// \param init_y The starting y position.
        ///
        Position(const double init_x, const double init_y);
        
        ///
        /// Returns the matrix x pixel value.
        ///
        int MatrixX();

        ///
        /// Returns the matrix y pixel value.
        ///
        int MatrixY();

        ///
        /// x position.
        ///
        double x;

        ///
        /// y position.
        ///
        double y;
    };
}

#endif