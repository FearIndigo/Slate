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
        /// Reset the game.
        ///
        void Reset();
        
        ///
        /// The main game loop.
        ///
        void Run(rgb_matrix::FrameCanvas *canvas, Slate::Input &input, const rgb_matrix::Font &font, const unsigned int frame_time);
    private:
    };
}