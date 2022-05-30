#include <signal.h>

#include "src/core/display/display.hpp"
#include "src/core/input/input.hpp"
#include "src/games/ponglord/main.hpp"

volatile bool interrupt_received = false;
static void InterruptHandler(int signo) {
	interrupt_received = true;
}

int main(int argc, char *argv[]) {

  	// It is always good to set up a signal handler to cleanly exit when we
  	// receive a CTRL-C for instance. The DrawOnCanvas() routine is looking
  	// for that.
  	signal(SIGTERM, InterruptHandler);
  	signal(SIGINT, InterruptHandler);

	try {
		// Initialize display
		Slate::Display display(argc, argv, "adafruit-hat-pwm", 32, 64, false);
	
		// Initialize input
		Slate::Input input("/dev/ttyACM0",9600);

		// DEBUG. Create instance of ponglord game
		Ponglord::Game pong;
		
		// Main loop
		while (!interrupt_received){
			// Read serial and save inputs to values array
    		input.Update();

			// DEBUG. Display ponglord thumbnail
			pong.Display(display.canvas);
			
    		// DEBUG. Set pixels on/off based on input values
			display.canvas->SetPixel(0,0,0,0,input.Value(0)?255:0);
			display.canvas->SetPixel(0,31,0,0,input.Value(1)?255:0);
			display.canvas->SetPixel(63,0,0,0,input.Value(2)?255:0);
			display.canvas->SetPixel(63,31,0,0,input.Value(3)?255:0);
  		}
	}
	catch(...)
	{
		return 1;
	}
	
  	return 0;
}
