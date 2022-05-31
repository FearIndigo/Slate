#ifndef SLATE_CORE_INPUT
#define SLATE_CORE_INPUT

#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdexcept>
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
        /// Read inputs from serial update values.
        ///
        void Update(const unsigned int frame_time);

		///
		/// Get the pressed state of a button
		///
		/// \param index The index of what button to get (0 = player1 left, 1 = player1 right, 2 = player2 left, 3 = player2 right).
		/// 
		bool GetButton(int index);

    	///
    	/// Get the long pressed state of a button
    	///
    	/// \param index The index of what button to get (0 = player1 left, 1 = player1 right, 2 = player2 left, 3 = player2 right).
    	/// 
    	bool GetButtonLongPress(int index);

    	///
    	/// Get the percentage of longPress the button has been pressed for (0 = not pressed, 1 = long press triggered)
    	///
    	/// \param index The index of what button to get (0 = player1 left, 1 = player1 right, 2 = player2 left, 3 = player2 right).
    	///
    	float GetButtonLongPressPercentage(int index);

    	///
    	/// Reset button long press value.
    	///
    	/// \param index The index of what button to get (0 = player1 left, 1 = player1 right, 2 = player2 left, 3 = player2 right).
    	///
    	void ResetLongPress(int index);
    	
    	///
    	/// Reset all button long press values.
    	///
    	void ResetLongPressAll();
    private:
        ///
        /// The file descriptor used to define which device is used to read serial.
        ///
        int fd;

        ///
        /// The byte received from the most recent serialGetchar(fd).
        ///
        unsigned char serialRead;

    	///
    	/// How long a button needs to be pressed to trigger a long press (milliseconds)
    	///
		unsigned int longPress;
    	
		///
        /// The pressed state of player buttons.
        ///
        bool pressed[4];

    	///
    	/// How long each button has been pressed
    	///
    	unsigned int pressedDuration[4];
    };
}

#endif
