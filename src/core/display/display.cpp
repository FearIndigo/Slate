#include "display.hpp"

namespace Slate
{
    Display::Display(int argc, char *argv[], const char* hardwareMapping, const int rows, const int cols, const bool showRefresh)
    {
        RGBMatrix::Options defaults;
        defaults.hardware_mapping = hardwareMapping;
        defaults.rows = rows;
        defaults.cols = cols;
        defaults.show_refresh_rate = false;
        matrix = RGBMatrix::CreateFromFlags(&argc, &argv, &defaults);
        if (matrix == NULL)
            throw std::invalid_argument("Failed to create canvas.");
    }

    Display::~Display()
    {
        if (matrix == NULL) return;
        matrix->Clear();
        delete matrix;
    }
}
