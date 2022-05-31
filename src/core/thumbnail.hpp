#include "led-matrix.h"
#include "graphics.h"
#include <stdexcept>

namespace Slate
{
    class Thumbnail
    {
    public:
        ///
        /// Main constructor.
        ///
        Thumbnail(const char* text);

        ///
        /// Display the thumbnail.
        ///
        /// \param canvas Frame canvas to display thumbnail on.
        /// \param frame_time Frame delta time.
        ///
        void Display(rgb_matrix::FrameCanvas *canvas, const unsigned int frame_time);
    private:
        ///
        /// Font used for display.
        ///
        rgb_matrix::Font font;

        ///
        /// Colour used for display.
        ///
        rgb_matrix::Color color;
        
        ///
        /// The game title.
        ///
        const char* title;
        
        ///
        /// How many x axis pixels the title takes up.
        ///
        int length;
        
        ///
        /// Text display x value.
        ///
        int x;
        
        ///
        /// How long the current display frame has been displayed for.
        ///
        int step;
    };
}