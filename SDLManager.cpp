// Project-specific Includes
#include "SDLManager.h"

// Standard Library Includes
#include <iostream>

// Third Party Library Includes
#include <SDL.h>


// CONSTRUCTOR
SDLManager::SDLManager() : initialized(false) {} // Initialize the static member variable 'initialized' to 'false' ensuring that 'initialized' is set to 'false' when an 'SDLManager' object is created, indicating that SDL has not been initialized yet

// DESTRUCTOR
SDLManager::~SDLManager() {
    cleanup();
}

// INITIALIZE SDL
bool SDLManager::initialize() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) { // SDL_Init initializes the SDL library with the SDL_INIT_VIDEO subsystem
        throw std::runtime_error("Could not initialize SDL! SDL_Error: " + std::string(SDL_GetError()));
    }
    initialized = true; // Sets the member variable initialized to true indicating that SDL has been successfully initialized
    return true; // Returns true to indicate that the initialization process was successful
}

// CLEANUP
void SDLManager::cleanup() {
    if (initialized) { // Start an 'if' statement that checks for our member variable 'initialized' to be true
        SDL_Quit(); // If our member variable is true 'SDL_Quit()' is called to clean up SDL resources
        initialized = false; // Set 'initialized' to 'false' to indicate SDL is no longer initialized
    }
}