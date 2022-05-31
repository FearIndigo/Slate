#include "input.hpp"

namespace Slate
{
    Input::Input(const char* device,const int baud)
    {
        // Set duration button is pressed to trigger a long press
        longPress = 1000;
        if((fd=serialOpen(device,baud))<0){
            fprintf(stderr,"Unable to open serial device: %s\n",strerror(errno));
            throw std::invalid_argument("Failed to setup player inputs.");
        }
    }

    void Input::Update(const unsigned int frame_time)
    {
        serialRead = serialGetchar(fd);
        for (int i=0; i < 4; ++i)
        {
            pressed[i] = (serialRead & (1<<i)) != 0;

            if(pressed[i])
            {
                pressedDuration[i] += frame_time;
            }
            else
            {
                pressedDuration[i] = 0;
            }
        }
    }

	bool Input::GetButton(int index)
	{
		return pressed[index];
	}

    bool Input::GetButtonLongPress(int index)
    {
        return pressedDuration[index] >= longPress;
    }

    double Input::GetButtonLongPressPercentage(int index)
    {
        return std::clamp((double)pressedDuration[index] / (double)longPress, 0.0, 1.0);
    }
}
