#include <string>
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
        void Input(std::string_view device,int baud);

        ///
        /// Read inputs from serial and set the decoded values.
        ///
        void Update();

        ///
        /// The decoded input value of each player button.
        ///
        bool[] inputs;
    private:
        ///
        /// The file descriptor used to define which device is used to read serial.
        ///
        const int fd;

        ///
        /// The byte received from the most recent serialGetchar(fd).
        ///
        unsigned char serialRead;
    };
}