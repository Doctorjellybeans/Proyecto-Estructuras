#include "states/start.h"

#include "states/duel.h"
#include <stdio.h>

StartState::StartState(StateQueue* origin) {

    this->origin = origin;

    this->window = new RenderWindow("TDA-OH!", 800, 600);

    // Carga las texturas de los botones
    Texture* texure = window->loadTexture("assets/images/play_button.png");
    playButton.setTexture(texure);
    playButton.setPosition(219, 308);

    texure = window->loadTexture("assets/images/rules_button.png");
    rulesButton.setTexture(texure);
    rulesButton.setPosition(219, 396);

    texure = window->loadTexture("assets/images/quit_button.png");
    quitButton.setTexture(texure);
    quitButton.setPosition(219, 484);

    // Fondo
    backgroundTexture = window->loadTexture("assets/images/background1.png");
    background.setTexture(backgroundTexture);
}

StartState::~StartState() {
    delete this->window;

    destroyTexture(playButton.texure);
    destroyTexture(rulesButton.texure);
    destroyTexture(quitButton.texure);

    destroyTexture(backgroundTexture);
}

void StartState::update() {

    int x, y;
    unsigned int mouseState = SDL_GetMouseState(&x, &y);

    if (mouseState & SDL_BUTTON(SDL_BUTTON_LEFT)) {
        
        if (playButton.isClicked(x, y)) {
            State* s = new DuelState(origin);
            pushState(s);
            end();
        }

        if (rulesButton.isClicked(x, y)) {
            printf("reglas\n");
        }

        if (quitButton.isClicked(x, y)) {
            end();
        }
    }

    background.move(-1, -1);
    if ( background.getPosition().x <= -80.0f) {
        background.setPosition(0, background.getPosition().y);
    }

    if ( background.getPosition().y <= -80.0f) {
        background.setPosition(background.getPosition().x, 0);
    }
}

void StartState::pollEvents() {
    
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            end();
            break;
        }
    }
}

void StartState::render() {
    draw(background);

    draw(playButton.sprite);
    draw(rulesButton.sprite);
    draw(quitButton.sprite);
}

void StartState::clear() {
    this->window->display();
    this->window->clear();
}