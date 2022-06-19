#include "time.hpp"

namespace Slate
{
    Time::Time()
        : max_frame_time(30)
    {
        // Get current time
        new_time = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        current_time = new_time;
    }

    unsigned int Time::Update()
    {
        // Calculate frame time.
        new_time = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        frame_time = new_time - current_time;
        frame_time = frame_time > max_frame_time ? max_frame_time : frame_time;
        current_time = new_time;

        return frame_time;
    }
}
