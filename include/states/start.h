#ifndef STATE_START_H
#define STATE_START_H

#include "state.h"
#include "graphics.h"

class StartState : public State {

public:

    StartState();
    ~StartState();

    void update();
    void render();
    void clear();

private:

    RenderWindow* window;
    Text title;
};

#endif // STATE_START_H