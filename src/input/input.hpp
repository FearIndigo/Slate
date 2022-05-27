#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <wiringSerial.h>

namespace Slate
{
    class Input
    {
    public:
        ///
        /// Main constructor.
        ///
        /// \param device Port serial device is connected to.
        /// \param baud Baudrate of the serial device.
        ///
        Input(const char* device,const int baud);

        ///
        /// Read inputs from serial and set the decoded values.
        ///
        void Update();

        ///
        /// The decoded input values of each player button.
        ///
        bool values[4];
    private:
        ///
        /// The file descriptor used to define which device is used to read serial.
        ///
        int fd;

        ///
        /// The byte received from the most recent serialGetchar(fd).
        ///
        unsigned char serialRead;
    };
}