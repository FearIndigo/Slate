#include "input.hpp"

namespace Slate
{
    Input::Input(const char* device,const int baud)
    {
        std::cout << "/dev/ttyACM0";
        if((fd=serialOpen("/dev/ttyACM0",baud))<0){
            fprintf(stderr,"Unable to open serial device: %s\n",strerror(errno));
            throw std::invalid_argument( "Failed to setup player inputs." );
        }
    }

    void Input::Update()
    {
        serialRead = serialGetchar(fd);
        for (int i=0; i < 4; ++i)
            values[i] = (serialRead & (1<<i)) != 0;
    }
}
