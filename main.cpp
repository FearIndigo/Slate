﻿#include <signal.h>

#include "src/core/display/display.hpp"
#include "src/core/input/input.hpp"
#include "src/core/time/time.hpp"

#include "src/games/ponglord/main.hpp"
#include "src/games/test/main.hpp"

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

		// Initialize time
		Slate::Time time;
		unsigned int frame_time;

		// Long press visual colour
		rgb_matrix::Color longPressColor(64,64,64);
		
		// DEBUG.
		Slate::BaseGame games[2] = {
			Ponglord::Game pong,
			Test::Game test
		};
		int gameIndex = 0;
		
		// Main loop
		while (!interrupt_received){
			// Clear canvas
			display.canvas->Clear();
			
			// Get new frame time
			frame_time = time.Update();
			
			// Update player inputs
    		input.Update(frame_time);

			// Visual representation of button long press
			if(!games[gameIndex].isRunning || games[gameIndex].showLongPress)
			{
				rgb_matrix::DrawLine(display.canvas, -1, 0, -1 + input.GetButtonLongPressPercentage(0)*16, 0, longPressColor);
				rgb_matrix::DrawLine(display.canvas, 32, 0, 32 - input.GetButtonLongPressPercentage(1)*16, 0, longPressColor);
				rgb_matrix::DrawLine(display.canvas, -1, 63, -1 + input.GetButtonLongPressPercentage(2)*16, 63, longPressColor);
				rgb_matrix::DrawLine(display.canvas, 32, 63, 32 - input.GetButtonLongPressPercentage(3)*16, 63, longPressColor);
			}
			
			if(games[gameIndex].isRunning)
			{
				// DEBUG. Run pong main loop
				games[gameIndex].Run(display.canvas, input, frame_time);
			}
			else
			{
				// DEBUG. Display game thumbnail
				games[gameIndex].Display(display.canvas, frame_time);

				// DEBUG. move to next game index
				if(input.GetButtonLongPress(0) && input.GetButtonLongPressPercentage(1) == 0)
				{
					input.ResetLongPress(0);
					gameIndex = (gameIndex + 1) % 2;
				}
				// DEBUG. move to previous game index
				if(input.GetButtonLongPress(1) && input.GetButtonLongPressPercentage(0) == 0)
				{
					input.ResetLongPress(1);
					gameIndex = (gameIndex - 1) % 2;
				}
				// DEBUG. move to next game index
				if(input.GetButtonLongPress(3) && input.GetButtonLongPressPercentage(2) == 0)
				{
					input.ResetLongPress(3);
					gameIndex = (gameIndex + 1) % 2;
				}
				// DEBUG. move to previous game index
				if(input.GetButtonLongPress(2) && input.GetButtonLongPressPercentage(3) == 0)
				{
					input.ResetLongPress(2);
					gameIndex = (gameIndex - 1) % 2;
				}
				
				// Run the current game when either player long presses both buttons
				if((input.GetButtonLongPress(0) && input.GetButtonLongPress(1)) ||
					(input.GetButtonLongPress(2) && input.GetButtonLongPress(3)))
				{
					games[gameIndex].isRunning = true;
					input.ResetLongPressAll();
				}
			}

			display.canvas = display.matrix->SwapOnVSync(display.canvas);
  		}
	}
	catch(...)
	{
		return 1;
	}
	
  	return 0;
}
