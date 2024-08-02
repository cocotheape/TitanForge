// Preprocessor Definitions
#define SDL_MAIN_HANDLED

// Standard Library Includes
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

// Third Party Library Includes
#include <SDL.h>
#include <SDL_vulkan.h>
#include <vulkan/vulkan.h>

// Project-specific Includes
#include "SDLManager.h"
#include "SurfaceWindow.h"

int main() {
	try {
		SDLManager sdlManager; // Creating an instance of the SDLManager class
		sdlManager.initialize(); // Initializing SDL


		SurfaceWindow surfaceWindow; // Creating an instance of the SurfaceWindow class
		surfaceWindow.createWindow("TitanForge", 1920, 1020); // Creating the window and define its attributes
		surfaceWindow.createRenderer(); // Creating the renderer

		bool running = true; // Creating the variable 'running' and setting it to 'true' 
		SDL_Event event = {}; // Initialize the event variable which will hold event data to zero 

		while (running) { // While loop runs as long as running evaluates to 'true'
			while (SDL_PollEvent(&event)) { // Retrieves the next event from the event queue and stores it in event // The loop will continue as long as there are events to process so as long as SDL_PollEvent will returns 1  // 'SDL_PollEvent' is used to retrieve events from the SDL event queue, it returns 1 if there is an event in queue and 0 if theres not // '&event' is the adress of the 'event' variable (a pointer to SDL_Event). This allows SDL_PollEvent to directly modify the 'event' variable with the event data
				if (event.type == SDL_QUIT) { // Checks the type of event, if the type evaluates to SDL_QUIT which corresponds to closing the window the code inside of the 'if' statement body will execute
					running = false; // Stops the loop when the window close event is detected
				}
			}
			
			SDL_Renderer* surfaceRenderer = surfaceWindow.getRenderer(); // Obtain the renderer associated with the 'surfaceWindow' object // 'surfaceWindow' An instance of the 'SurfaceWindow' class that manages the SDL window and renderer // 'getRenderer()' A method of the SurfaceWindow class that returns a pointer to the SDL_Renderer // This line assigns the SDL_Renderer pointer returned by 'surfaceWindow.getRenderer()' to the variable 'surfaceRenderer'.
			SDL_SetRenderDrawColor(surfaceRenderer, 37, 37, 37, 255); // Set the renderer draw color
			SDL_RenderClear(surfaceRenderer); // Clear the screen with the draw color
			SDL_RenderPresent(surfaceRenderer); // Make the latest rendering visible by swapping the back buffer with the front buffer
		}

		surfaceWindow.cleanup();
		sdlManager.cleanup();

		return 0;
	} 

	// Catch blocks
	catch (const std::runtime_error& e) { // 'e' is a variable which represents the caught exception object // 'const' indicates that the caught exception wont be modified // '&' indicates that the exception is being caught by reference, avoiding copys
		std::cerr << "Runtime error: " << e.what() << std::endl; // 'std::cerr' is used to output error messages into the standard error stream immediately // 'e.what()' calls the 'what()' method on the exception object 'e', which returns a descriptive error message
		return -1;
	} 
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
		return -1;
	} 
	catch (...) {
		std::cerr << "Unknown exception occurred!" << std::endl;
		return -1;
	}

	return 0;
}