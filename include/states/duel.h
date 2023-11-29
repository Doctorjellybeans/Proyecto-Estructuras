#ifndef STATES_DUEL_H
#define STATES_DUEL_H

#include "state.h"
#include "graphics.h"

class DuelState : public State {

public:

    DuelState(StateQueue* origin);
    ~DuelState();

    void update();
    void render();
    void clear();

    void pollEvents();

private:

    RenderWindow* window1;
    RenderWindow* window2;

    Sprite sprite1;
    Sprite sprite2;

    Texture* tex1;
    Texture* tex2;

};


#endif //STATES_DUEL_H