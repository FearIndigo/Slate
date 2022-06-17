#include <stdexcept>
#include "led-matrix.h"

namespace Slate
{
    class Display
    {
    public:
        ///
        /// Main constructor.
        ///
        /// \param argc Command line argument count.
        /// \param argv Command line argument vector.
        /// \param hardwareMapping Type of hardware used to drive matrix.
        /// \param rows Number of rows in the matrix.
        /// \param cols Number of columns in the matrix.
        /// \param showRefresh Display the refresh rate in the console.
        ///
        Display(int argc, char *argv[], const char* hardwareMapping, const int rows, const int cols, const bool showRefresh);

		///
        /// Destructor.
        ///
		~Display();		

        ///
        /// The display matrix.
        ///
        rgb_matrix::RGBMatrix *matrix;

        ///
        /// The frame canvas.
        ///
        rgb_matrix::FrameCanvas *canvas;
    private:
    };
}