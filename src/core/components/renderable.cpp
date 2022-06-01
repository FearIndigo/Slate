#include "renderable.hpp"

namespace Slate
{
    Renderable::Renderable(const std::vector<Slate::Pixel> default_pixels)
        : pixels(default_pixels) {}

    void Renderable::Draw(rgb_matrix::FrameCanvas *canvas, const Slate::Position &pos)
    {
        for (const auto &p : pixels)
            canvas->SetPixel(pos->x + p->rel_x, pos->y + p->rel_y, p->r, p->g, p->b);
    }
}
