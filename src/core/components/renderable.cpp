#include "renderable.hpp"

namespace Slate
{
    Renderable::Renderable(const std::vector<Slate::Pixel> default_pixels)
        : pixels(p) {}

    void Draw(rgb_matrix::FrameCanvas *canvas, const Slate::Position pos)
    {
        for (p : pixels)
            canvas->SetPixel(pos.x + p.rel_x, pos.y + p.rel_y, p.r, p.g, p.b);
    }
}
