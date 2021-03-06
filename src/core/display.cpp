#include "display.hpp"

namespace Slate
{
    Display::Display(int argc, char *argv[], const char* hardwareMapping, const int rows, const int cols, const bool showRefresh)
    {
        rgb_matrix::RGBMatrix::Options defaults;
        defaults.hardware_mapping = hardwareMapping;
        defaults.rows = rows;
        defaults.cols = cols;
        defaults.show_refresh_rate = false;
        defaults.pixel_mapper_config="Rotate:90";
        matrix = rgb_matrix::RGBMatrix::CreateFromFlags(&argc, &argv, &defaults);
        if (canvas == NULL)
            throw std::invalid_argument("Failed to create canvas.");
        canvas = matrix->CreateFrameCanvas();
    }

    Display::~Display()
    {
        if (matrix == NULL) return;
        matrix->Clear();
        delete matrix;
    }
}
