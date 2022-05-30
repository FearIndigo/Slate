#include "led-matrix.h"
#include "graphics.h"

namespace Slate
{
    class BaseGame
    {
    public:
        ///
        /// Main constructor.
        ///                                               
        BaseGame();

        ///
        /// Display the games thumbnail.
        ///
        virtual void Display(rgb_matrix::Canvas *canvas);
        
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
        rgb_matrix::Color color;
        
        ///
        /// The game title
        ///
        char* title;

        ///
        /// The thumbnail image.
        ///
        //??? thumbnail;
    };
}