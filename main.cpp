#include <signal.h>

#include "src/core/display/display.hpp"
#include "src/core/input/input.hpp"

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
		rgb_matrix::FrameCanvas *offscreen_canvas = display.canvas->CreateFrameCanvas();

		// Load font
		rgb_matrix::Font font;
		if (!font.LoadFont("matrix/fonts/8x13.bdf")) {
			fprintf(stderr, "Couldn't load font '%s'\n", "matrix/fonts/8x13.bdf");
			return 1;
		}

		// Font color
		Color color(128, 128, 128);
		
		// Main loop
		while (!interrupt_received){
			// Read serial and save inputs to values array
    		input.Update();

			// DEBUG, draw text
			rgb_matrix::DrawText(offscreen_canvas, font,
									32, 16 + font.baseline(),
									color, NULL,
									"Test", 0);
			
    		// DEBUG. Set pixels on/off based on input values
			if(input.Value(0))
    			offscreen_canvas->SetPixel(0,0,0,0,255);
			if(input.Value(1))
    			offscreen_canvas->SetPixel(0,31,0,0,255);
			if(input.Value(2))
    			offscreen_canvas->SetPixel(63,0,0,0,255);
			if(input.Value(3))
    			offscreen_canvas->SetPixel(63,31,0,0,255);

			// Swap the offscreen_canvas with canvas on vsync, avoids flickering
			offscreen_canvas = display.canvas->SwapOnVSync(offscreen_canvas);
  		}
	}
	catch(...)
	{
		return 1;
	}
	
  	return 0;
}
