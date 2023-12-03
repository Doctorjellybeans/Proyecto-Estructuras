#include "states/duel.h"


DuelState::DuelState(StateQueue* origin) {
    this->origin = origin;

    // Inicializa Ventanas
    window1 = new RenderWindow("TDA-OH! - Jugador1", 400, 400, 300);
    window2 = new RenderWindow("TDA-OH! - Jugador2", 400, 400, 800);

    this->textures = new TextureManager(window1, window2);

    // Inicializa Juegadores
    player1 = new Player(100, TDAType::STACK);
    player2 = new Player(100, TDAType::STACK);



    // Fondos
    Texture* texture = getTexture("assets/images/player1_background.png", 1);
    background1.setTexture(texture);

    texture = getTexture("assets/images/player2_background.png", 2);
    background2.setTexture(texture);
}

DuelState::~DuelState() {
    delete player1;
    delete player2;
    delete window1;
    delete window2;
}

void DuelState::update() {

    // Fondo 1
    background1.move(-0.35 * gDeltaTime, -0.35 * gDeltaTime);
    if ( background1.getPosition().x <= -16.0f) {
        background1.setPosition(0, background1.getPosition().y);
        background1.setPosition(background1.getPosition().x, 0);
    }

    // Fondo 2
    background2.move(-0.35 * gDeltaTime, -0.35 * gDeltaTime);
    if ( background2.getPosition().x <= -16.0f) {
        background2.setPosition(0, background2.getPosition().y);
        background2.setPosition(background2.getPosition().x, 0);
    }
}

void DuelState::render() {
    draw(background1, 1);
    draw(background2, 2);
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