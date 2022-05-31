#include <stdexcept>
#include "../../core/base/baseGame.hpp"

namespace Test
{
    class Game : public Slate::BaseGame
    {
    public:
        ///
        /// Main constructor.
        ///                                               
        Game();
        
        ///
        /// The main game loop.
        ///
        void Run(rgb_matrix::FrameCanvas *canvas, Slate::Input &input, const unsigned int frame_time);
    private:
    };
}