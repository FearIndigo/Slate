#include "core/baseGame.hpp"

namespace Test
{
    class Game : public Slate::BaseGame
    {
    public:
        ///
        /// Main constructor.
        ///                                               
        Game(const char* testTitle);
        
        ///
        /// The main game loop.
        ///
        void Run(rgb_matrix::FrameCanvas *canvas, Slate::Input &input, const unsigned int frame_time);
    private:
    };
}