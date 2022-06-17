#include <signal.h>
#include <iterator>
#include <iostream>
#include "graphics.h"

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

		// Load font
		rgb_matrix::Font font;
		if (!font.LoadFont("matrix/fonts/4x6.bdf")) {
			fprintf(stderr, "Couldn't load font '%s'\n", "matrix/font/4x6.bdf");
			return 1;
		}
		
		// Long press visual colour
		rgb_matrix::Color long_press_color(64,64,64);
		
		// DEBUG. Create all game classes
		Slate::BaseGame* games[] = {
			new Ponglord::Game(),
			new Test::Game("TEST GAME 001"),
			new Test::Game("TEST GAME 002")
		};
		int games_count = std::size(games);
		int game_index = 0;
		bool is_running = false;

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
			
			if(is_running)
			{
				// Run game main loop
				games[game_index]->Run(display.canvas, input, font, frame_time);

				// Return to main menu if all buttons have been long pressed
				if(input.GetButtonLongPress(0) && input.GetButtonLongPress(1) &&
					input.GetButtonLongPress(2) && input.GetButtonLongPress(3))
				{
					is_running = false;
					input.ResetLongPressAll();
					games[game_index]->thumbnail->Reset();
				}
			}
			else
			{
				// Visual representation of button long press in main menu
				rgb_matrix::DrawLine(display.canvas, -1, 0, -1 + input.GetButtonLongPressPercentage(0)*16, 0, long_press_color);
				rgb_matrix::DrawLine(display.canvas, 32, 0, 32 - input.GetButtonLongPressPercentage(1)*16, 0, long_press_color);
				rgb_matrix::DrawLine(display.canvas, -1, 63, -1 + input.GetButtonLongPressPercentage(2)*16, 63, long_press_color);
				rgb_matrix::DrawLine(display.canvas, 32, 63, 32 - input.GetButtonLongPressPercentage(3)*16, 63, long_press_color);
				
				// Display game thumbnail
				games[game_index]->thumbnail->Display(display.canvas, font, frame_time);

				// Player 1 move to next game index
				if(input.GetButtonLongPress(1) && input.GetButtonLongPressPercentage(0) == 0)
				{
					input.ResetLongPress(1);
					game_index = (game_index + 1) % games_count;
					games[game_index]->thumbnail->Reset();
				}
				// Player 1 move to previous game index
				if(input.GetButtonLongPress(0) && input.GetButtonLongPressPercentage(1) == 0)
				{
					input.ResetLongPress(0);
					game_index = game_index == 0 ? games_count - 1 : (game_index - 1) % games_count;
					games[game_index]->thumbnail->Reset();
				}
				// Player 2 move to next game index
				if(input.GetButtonLongPress(3) && input.GetButtonLongPressPercentage(2) == 0)
				{
					input.ResetLongPress(3);
					game_index = (game_index + 1) % games_count;
					games[game_index]->thumbnail->Reset();
				}
				// Player 2 move to previous game index
				if(input.GetButtonLongPress(2) && input.GetButtonLongPressPercentage(3) == 0)
				{
					input.ResetLongPress(2);
					game_index = game_index == 0 ? games_count - 1 : (game_index - 1) % games_count;
					games[game_index]->thumbnail->Reset();
				}
				
				// Run the current game when either player long presses both buttons
				if((input.GetButtonLongPress(0) && input.GetButtonLongPress(1)) ||
					(input.GetButtonLongPress(2) && input.GetButtonLongPress(3)))
				{
					is_running = true;
					input.ResetLongPressAll();
					games[game_index]->Reset();
					games[game_index]->thumbnail->Reset();
				}
			}

			// Send new frame canvas to matrix display
			display.canvas = display.matrix->SwapOnVSync(display.canvas);
  		}
	}
	catch(...)
	{
		std::cout << "Oops. Something went wrong...";
		return 1;
	}
	
  	return 0;
}
