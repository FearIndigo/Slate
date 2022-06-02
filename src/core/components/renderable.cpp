#include "renderable.hpp"

namespace Slate
{
    Renderable::Renderable(const std::vector<Slate::Pixel> default_pixels)
        : pixels(default_pixels) {}

    void Renderable::Draw(rgb_matrix::FrameCanvas *canvas, const Slate::Position &pos)
    {
        for (const auto &p : pixels)
            canvas->SetPixel(pos.MatrixX() + p.rel_x, pos.MatrixY() + p.rel_y, p.r, p.g, p.b);
    }
}
