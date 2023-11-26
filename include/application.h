#ifndef APPLIACATION_H
#define APPLIACATION_H

#include "state.h"
#include <SDL2/SDL_events.h>

class Application {

public:

    Application();
    ~Application();
    void run();

private:

    void update();
    void render();
    void pollEvents();

    State* currentState() { return this->states.top(); }

    StateQueue states;
    SDL_Event event;
};

#endif // APPLIACATION_H