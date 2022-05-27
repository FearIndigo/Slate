#include <string.h>
#include <errno.h>
#include <wiringSerial.h>

namespace Slate
{
    class Input
    {
    public:
        Input();
        ///
        /// Main constructor.
        ///
        /// \param device Port serial device is connected to.
        /// \param baud Baudrate of the serial device.
        ///
        Input(string device,int baud);

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