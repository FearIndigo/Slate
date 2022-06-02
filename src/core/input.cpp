#include "input.hpp"

namespace Slate
{
    Input::Input(const char* device,const int baud)
    {
        // Set duration button is pressed to trigger a long press
        long_press = 1000;
        if((fd=serialOpen(device,baud))<0){
            fprintf(stderr,"Unable to open serial device: %s\n",strerror(errno));
            throw std::invalid_argument("Failed to setup player inputs.");
        }
    }

    void Input::Update(const unsigned int frame_time)
    {
        serial_read = serialGetchar(fd);
        for (int i=0; i < 4; ++i)
        {
            pressed[i] = (serial_read & (1<<i)) != 0;

            if(pressed[i])
            {
                pressed_duration[i] += frame_time;
            }
            else
            {
                pressed_duration[i] = 0;
            }
        }
        serialFlush(fd);
    }

	bool Input::GetButton(int index) const
	{
		return pressed[index];
	}

    bool Input::GetButtonLongPress(int index) const
    {
        return pressed_duration[index] >= long_press;
    }

    float Input::GetButtonLongPressPercentage(int index) const
    {
        float temp = (float)pressed_duration[index] / (float)long_press;
        return temp > 1.0 ? 1.0 : temp;
    }

    void Input::ResetLongPress(int index)
    {
        pressed_duration[index] = 0;
    }
    
    void Input::ResetLongPressAll()
    {
        for (int i=0; i < 4; ++i)
        {
            ResetLongPress(i);
        }
    }
}
