﻿#include "input.hpp"

namespace Slate
{
    Input::Input(std::string_view device,int baud)
    {
        if((fd=serialOpen(device,baud))<0){
            fprintf(stderr,"Unable to open serial device: %s\n",strerror(errno));
            throw std::invalid_argument( "Failed to setup player inputs." );
        }
    }

    Input::Update()
    {
        serialRead = serialGetchar(fd);
        for (int i=0; i < 4; ++i)
            inputs[i] = (serialRead & (1<<i)) != 0;
    }
}
