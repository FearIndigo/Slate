#include <unistd.h>
#include <math.h>
#include <stdio.h>
#include <signal.h>

#include "src/input/input.hpp"

#include <entt/entt.hpp>
#include "led-matrix.h"

using rgb_matrix::RGBMatrix;
using rgb_matrix::Canvas;

volatile bool interrupt_received = false;
static void InterruptHandler(int signo) {
	interrupt_received = true;
}

void Shutdown(Canvas* canvas) {
	// Shut down the RGB matrix.
    canvas->Clear();
    delete canvas;
}

int main(int argc, char *argv[]) {
	RGBMatrix::Options defaults;
  	defaults.hardware_mapping = "adafruit-hat-pwm";
  	defaults.rows = 32;
  	defaults.cols = 64;
  	defaults.chain_length = 1;
  	defaults.parallel = 1;
  	defaults.show_refresh_rate = false;
  	Canvas *canvas = RGBMatrix::CreateFromFlags(&argc, &argv, &defaults);
  	if (canvas == NULL)
    	return 1;

  	// It is always good to set up a signal handler to cleanly exit when we
  	// receive a CTRL-C for instance. The DrawOnCanvas() routine is looking
  	// for that.
  	signal(SIGTERM, InterruptHandler);
  	signal(SIGINT, InterruptHandler);

	try {
		// Initialize input, define serial port and baudrate [default = ("/dev/ttyACM0", 9600)]
		Slate::Input input("/dev/serial0",9600);
		
		// Main loop
		for (;;){
			// Break out of loop when interrupt triggered
  			if (interrupt_received) break;
			
			// Read serial and save inputs to values array
    		input.Update();
    
    		// TEST, set pixels on/off based on input values
    		canvas->SetPixel(0,0,0,0,input.values[0]?255:0);
    		canvas->SetPixel(0,31,0,0,input.values[1]?255:0);
    		canvas->SetPixel(63,0,0,0,input.values[2]?255:0);
    		canvas->SetPixel(63,31,0,0,input.values[3]?255:0);
  		}
	}
	catch(...)
	{
		Shutdown(canvas);
		return 1;
	}

  	Shutdown(canvas);
  	return 0;
}
