#include "input.hpp"

namespace Slate
{
    Input::Input(std::string_view device,const int baud)
    {
        fprintf(device);
        if((fd=serialOpen(device,baud))<0){
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
