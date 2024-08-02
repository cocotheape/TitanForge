// Preprocessor Definitions
#ifndef SURFACEWINDOW_H
#define SURFACEWINDOW_H

// Third-Party Library Includes
#include <SDL.h>

// Standard Library Includes
#include <iostream>


class SurfaceWindow {
public:
    SurfaceWindow(); // Constructor
    ~SurfaceWindow(); // Destructor

    bool createWindow(const std::string& title, int width, int height); // Method which creates the SDL window // `const` prevents modification of 'std::string' // `&` avoids the creation of a copy of 'std::string' and instead references this object  
    bool createRenderer();
    void cleanup(); // Method to clean up SDL and window rescources // 'void' indicates that this method does not return a value
    SDL_Window* getWindow() const; // Method to create a getter for the window // The 'getWindow' method returns a pointer to a SDL_Window object which holds the data about our window // `const` ensures the method doesn't modify any member variables of the class
    SDL_Renderer* getRenderer() const; // Getter for a renderer

private:
    SDL_Window* surfaceWindow; // Privat member variable which returns a pointer to a SDL_Window object that holds the data about our window // Making this privat ensuring modification of the window is only possible within our class
    SDL_Renderer* surfaceRenderer; // Privat member variable which returns a pointer to a SDL_Renderer object that holds the data bout our renderer
};


#endif // SURFACEWINDOW_H