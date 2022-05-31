#include "time.hpp"

namespace Slate
{
    Time::Time()
    {
        // Get current time
        new_time = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    }

    unsigned int Time::Update()
    {
        // Calculate frame time.
        new_time = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        frame_time = new_time - current_time;
        current_time = new_time;

        return frame_time;
    }
}
