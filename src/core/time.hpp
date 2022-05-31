#include <chrono>

namespace Slate
{
    class Time
    {
    public:
        ///
        /// Main constructor.
        ///
        Time();

        ///
        /// Update and return the frame time.
        ///
        unsigned int Update();
    private:
    	unsigned long current_time;
    	unsigned long new_time;
    	unsigned int frame_time;
    };
}