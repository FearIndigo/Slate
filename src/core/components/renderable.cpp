#include "renderable.hpp"

namespace Slate
{
    Renderable::Renderable(const std::vector<Slate::Pixel> default_pixels)
        : pixels(p) {}

    void Draw(rgb_matrix::FrameCanvas *canvas, const Slate::Position position)
    {
        for (p : pixels)
            canvas->SetPixel(position.x + p.rel_x, position.y + p.rel_y, p.r, p.g, p.b);
    }
}
