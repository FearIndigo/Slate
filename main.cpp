#include <signal.h>

#include "src/core/display/display.hpp"
#include "src/core/input/input.hpp"

#include "graphics.h"

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

		// Create frame canvas
		rgb_matrix::FrameCanvas *canvas = display.matrix->CreateFrameCanvas();

		// Load font
		rgb_matrix::Font font;
		if (!font.LoadFont("matrix/fonts/8x13.bdf")) {
			fprintf(stderr, "Couldn't load font '%s'\n", "matrix/fonts/8x13.bdf");
			return 1;
		}

		// Font color
		rgb_matrix::Color color(128, 128, 128);
		
		// Main loop
		while (!interrupt_received){
			// Read serial and save inputs to values array
    		input.Update();

			// DEBUG. draw text
			rgb_matrix::DrawText(canvas, font,
									16, 6 + font.baseline(),
									color, NULL,
									"Ponglord", 0);
			
    		// DEBUG. Set pixels on/off based on input values
			canvas->SetPixel(0,0,0,0,input.Value(0)?255:0);
			canvas->SetPixel(0,31,0,0,input.Value(1)?255:0);
			canvas->SetPixel(63,0,0,0,input.Value(2)?255:0);
			canvas->SetPixel(63,31,0,0,input.Value(3)?255:0);

			// Swap the buffered canvas with displayed canvas on vsync, avoids flickering
			canvas = display.matrix->SwapOnVSync(canvas);
  		}
	}
	catch(...)
	{
		return 1;
	}
	
  	return 0;
}
