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
        const int max_frame_time;
    	unsigned long current_time;
    	unsigned long new_time;
    	unsigned int frame_time;
    };
}