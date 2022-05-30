#include "led-matrix.h"
#include "graphics.h"

namespace Slate
{
    class BaseGame
    {
    public:
        ///
        /// Display the games thumbnail.
        ///
        void Display(rgb_matrix::Canvas *canvas)
        {
            rgb_matrix::DrawText(canvas, font,
                                            0, 30 + font.baseline(),
                                            color, NULL,
                                            title, 0);
        }
        
        ///
        /// The main game loop.
        ///
        virtual void Run();
    protected:
        ///
        /// Font used for display.
        ///
        rgb_matrix::Font font;

        ///
        /// Colour used for display.
        ///
        const rgb_matrix::Color color;
        
        ///
        /// The game title
        ///
        const char* title;

        ///
        /// The thumbnail image.
        ///
        //??? thumbnail;
    };
}