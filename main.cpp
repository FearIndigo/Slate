#include "src/input/input.hpp"

#include <entt/entt.hpp>
#include "led-matrix.h"

using rgb_matrix::RGBMatrix;
using rgb_matrix::Canvas;

volatile bool interrupt_received = false;
static void InterruptHandler(int signo) {
  interrupt_received = true;
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
		Slate::Input inputHandler("/dev/ttyACM0",9600);
		
		for (;;){
  			if (interrupt_received)
  	  			break;

    		inputHandler.Update();
    
    		canvas->SetPixel(0,0,0,0,inputHandler.inputs[0]?255:0);
    		canvas->SetPixel(0,31,0,0,inputHandler.inputs[1]?255:0);
    		canvas->SetPixel(63,0,0,0,inputHandler.inputs[2]?255:0);
    		canvas->SetPixel(63,31,0,0,inputHandler.inputs[3]?255:0);
  		}
	}
	catch(...)
	{
		return 1;
	}

  	// Animation finished. Shut down the RGB matrix.
  	canvas->Clear();
  	delete canvas;

  	return 0;
}
