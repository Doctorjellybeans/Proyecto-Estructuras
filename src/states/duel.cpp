#include "states/duel.h"


DuelState::DuelState(StateQueue* origin) {

    this->origin = origin;

    this->window1 = new RenderWindow("TDA-OH! - Jugador1", 400, 400, 300);
    this->window2 = new RenderWindow("TDA-OH! - Jugador2", 400, 400, 800);

    tex1 = window1->loadTexture("assets/ihavet.png");
    sprite1.setTexture(tex1);

    tex2 = window2->loadTexture("assets/wosides.png");
    sprite2.setTexture(tex2);
}

DuelState::~DuelState() {
    delete this->window1;
    delete this->window2;
}

void DuelState::update() {

}

void DuelState::render() {
    window1->draw(sprite1);
    window2->draw(sprite2);
}

void DuelState::clear() {
    this->window1->display();
    this->window1->clear();

    this->window2->display();
    this->window2->clear();
}

void DuelState::pollEvents() {
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_WINDOWEVENT:
            switch (event.window.event)
            {
            case SDL_WINDOWEVENT_CLOSE:
                end();
                break;
            }
            break;

        case SDL_QUIT:
            end();
            break;
        }
    }
}