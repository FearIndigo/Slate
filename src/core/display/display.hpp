#include <signal.h>
#include <unistd.h>
#include "led-matrix.h"

using rgb_matrix::RGBMatrix;
using rgb_matrix::Canvas;

namespace Slate
{
    class Display
    {
    public:
        ///
        /// Main constructor.
        ///
        /// \param hardwareMapping Type of hardware used to drive matrix.
        /// \param rows Number of rows in the matrix.
        /// \param cols Number of columns in the matrix.
        /// \param showRefresh Display the refresh rate in the console
        ///
        Display(const char* hardwareMapping, const int rows, const int cols, const bool showRefresh);

		///
        /// Deconstructor
        ///
		~Display();		

        ///
        /// The display canvas.
        ///
        Canvas *canvas;
    private:
    };
}