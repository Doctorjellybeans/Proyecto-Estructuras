#ifndef APPLIACATION_H
#define APPLIACATION_H

#include "state.h"
#include <SDL2/SDL_events.h>

class Application {

public:

    Application();
    ~Application();
    
    // Bucle principal de la aplicación
    void run();

private:

    void update();
    void render();

    State* currentState() { return this->states.top(); }

    // Cola de estados
    StateQueue states;
};

#endif // APPLIACATION_H