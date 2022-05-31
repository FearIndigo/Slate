#include <signal.h>
#include <cmath>

#include "core/display.hpp"
#include "core/input.hpp"
#include "core/time.hpp"

#include "games/ponglord/main.hpp"
#include "games/test/main.hpp"

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

		// Long press visual colour
		rgb_matrix::Color longPressColor(64,64,64);
		
		// DEBUG. Create all game classes
		Slate::BaseGame* games[] = {
			new Ponglord::Game(),
			new Test::Game()
		};
		int gamesCount = 2;
		int gameIndex = 0;

		// Initialize time
		Slate::Time time;
		unsigned int frame_time;
		
		// Main loop
		while (!interrupt_received){
			// Clear canvas
			display.canvas->Clear();
			
			// Get new frame time
			frame_time = time.Update();
			
			// Update player inputs
    		input.Update(frame_time);
			
			if(games[gameIndex]->IsRunning)
			{
				// DEBUG. Run pong main loop
				games[gameIndex]->Run(display.canvas, input, frame_time);
			}
			else
			{
				// Visual representation of button long press in main menu
				rgb_matrix::DrawLine(display.canvas, -1, 0, -1 + input.GetButtonLongPressPercentage(0)*16, 0, longPressColor);
				rgb_matrix::DrawLine(display.canvas, 32, 0, 32 - input.GetButtonLongPressPercentage(1)*16, 0, longPressColor);
				rgb_matrix::DrawLine(display.canvas, -1, 63, -1 + input.GetButtonLongPressPercentage(2)*16, 63, longPressColor);
				rgb_matrix::DrawLine(display.canvas, 32, 63, 32 - input.GetButtonLongPressPercentage(3)*16, 63, longPressColor);
				
				// Display game thumbnail
				games[gameIndex]->DisplayThumbnail(display.canvas, frame_time);

				// DEBUG. move to next game index
				if(input.GetButtonLongPress(0) && input.GetButtonLongPressPercentage(1) == 0)
				{
					input.ResetLongPress(0);
					gameIndex = (gameIndex + 1) % gamesCount;
				}
				// DEBUG. move to previous game index
				if(input.GetButtonLongPress(1) && input.GetButtonLongPressPercentage(0) == 0)
				{
					input.ResetLongPress(1);
					gameIndex = std::abs((gameIndex - 1) % gamesCount);
				}
				// DEBUG. move to next game index
				if(input.GetButtonLongPress(3) && input.GetButtonLongPressPercentage(2) == 0)
				{
					input.ResetLongPress(3);
					gameIndex = (gameIndex + 1) % gamesCount;
				}
				// DEBUG. move to previous game index
				if(input.GetButtonLongPress(2) && input.GetButtonLongPressPercentage(3) == 0)
				{
					input.ResetLongPress(2);
					gameIndex = std::abs((gameIndex - 1) % gamesCount);
				}
				
				// Run the current game when either player long presses both buttons
				if((input.GetButtonLongPress(0) && input.GetButtonLongPress(1)) ||
					(input.GetButtonLongPress(2) && input.GetButtonLongPress(3)))
				{
					games[gameIndex]->IsRunning = true;
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
