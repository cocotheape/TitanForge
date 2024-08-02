#ifndef SDLMANAGER_H
#define SDLMANAGER_H

class SDLManager {
public:
	SDLManager(); // Constructor
	~SDLManager(); // Destructor

	bool initialize();
	void cleanup();

private:
	bool initialized;
};

#endif // SDLMANAGER_H