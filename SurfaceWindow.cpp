// Project-Specific Includes
#include "SurfaceWindow.h"

// Standard Library Includes
#include <stdexcept>
#include <iostream>


// CONSTRUCTOR
SurfaceWindow::SurfaceWindow() : surfaceWindow(nullptr), surfaceRenderer(nullptr) {} // Constructor initializing 'surfaceWindow' to 'nullptr' // The '::' operator specifies that this constructor belongs to the 'SurfaceWindow' class // The ':' accesses the member initializer list, a list of all member variables inside the class // 'nullptr' inside the parentheses initilaizes the member variable to a nullptr

// DESTRUCTOR
SurfaceWindow::~SurfaceWindow() {
    cleanup();
}

// WINDOW CREATION
bool SurfaceWindow::createWindow(const std::string& title, int width, int height) {

    surfaceWindow = SDL_CreateWindow( // The '=' operator assigns the value (pointer) returned by SDL_CreateWindow to the surfaceWindow member variable
        title.c_str(), // Converts the 'std::string' title to a C-style string (const char*) which is necessary for SDL
        SDL_WINDOWPOS_CENTERED, // Centers the window horizontally on the screen
        SDL_WINDOWPOS_CENTERED, // Centers the window vertically on the screen
        width, // The width of the window
        height, // The height of the window
        SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE); // FLAGS // SDL_WINDOW_SHOWN: Makes the window visible // SDL_WINDOW_RESIZABLE: Makes the window resizable

    if (!surfaceWindow) { // Checks if 'surfaceWindow' is null (or 'nullptr') and executes the code inside the body if that condition is met // In C++ pointers (in our case 'surfaceWindow) can be evaluated in a boolean context, if a pointer points to a valid memory adress it is 'true', if it does not point to any memory adress (= 'nullptr') it is 'false'. The '!' operator is a logical "NOT" operator, it inverts the boolean value that follows it so true becomes false and vice versa
        throw std::runtime_error("Window could not be created! SDL_Error: " + std::string(SDL_GetError()));
    }
    return true;
}

// RENDERER CREATION
bool SurfaceWindow::createRenderer() {
    surfaceRenderer = SDL_CreateRenderer(surfaceWindow, -1, SDL_RENDERER_ACCELERATED);
    if (!surfaceRenderer) {
        throw std::runtime_error("Renderer could not be created! SDL_Error: " + std::string(SDL_GetError()));
    }
    return true;
}

// CLEANUP
void SurfaceWindow::cleanup() {
    if (surfaceWindow) { // 'If' statement to check if 'surfaceWindow' is not equal to null (or 'nullptr'), if it is not the code inside of the 'if' blocks executes // A pointer can be used in a boolean context. If a pointer is not 'nullptr' it evaluates to true and vice versa so in this case: 'if (surfaceWindow)' is equivalent to 'if (surfaceWindow != nullptr)'
        SDL_DestroyWindow(surfaceWindow); // Destroys the window associated with 'surfaceWindow'
        surfaceWindow = nullptr; // Sets the 'surfaceWindow' pointer to null after the window has been destroyed // Reason: This helps prevent accidental access or modification of a window that no longer exists, avoiding potential crashes or undefined behavior
    }
    if (surfaceRenderer) {
        SDL_DestroyRenderer(surfaceRenderer);
        surfaceRenderer = nullptr;
    }
}

// GETTERS
SDL_Window* SurfaceWindow::getWindow() const {
    return surfaceWindow; // Returns a pointer to a SDL window (refer to corresponding header file)
}
SDL_Renderer* SurfaceWindow::getRenderer() const {
    return surfaceRenderer;
}


