#include "states/duel.h"


DuelState::DuelState(StateQueue* origin) {

    this->origin = origin;

    this->window1 = new RenderWindow("TDA-OH! - Jugador1", 400, 400, 300);
    this->window2 = new RenderWindow("TDA-OH! - Jugador2", 400, 400, 800);

    text1.setText("Jugador 1");
    text1.setSize(14);

    text2.setText("Jugador 2");
    text2.setSize(14);
}

DuelState::~DuelState() {
    delete this->window1;
    delete this->window2;
}

void DuelState::update() {

}

void DuelState::render() {
    draw(text1, 1);
    draw(text1, 2);
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

void DuelState::draw(const Drawable& drawable, int value) const {
    if (value == 1) {
        this->window1->draw(drawable);
    }
    else {
        this->window2->draw(drawable);
    }
}