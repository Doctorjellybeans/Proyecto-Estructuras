#include "states/duel.h"


DuelState::DuelState(StateQueue* origin) {

    this->origin = origin;

    this->window1 = new RenderWindow("TDA-OH! - Jugador1", 400, 400, 300);
    this->window2 = new RenderWindow("TDA-OH! - Jugador2", 400, 400, 800);

    this->textures = new TextureManager(this->window1, this->window2);
    
    tex1 =  getTexture("assets/ihavet.png", 1);
    sprite1.setTexture(tex1);

    tex2 = getTexture("assets/wosides.png", 2);
    sprite2.setTexture(tex2);
}

DuelState::~DuelState() {
    delete this->window1;
    delete this->window2;
}

void DuelState::update() {

}

void DuelState::render() {
    draw(sprite1, 1);
    draw(sprite2, 2);
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