#include "states/start.h"

#include "states/duel.h"
#include <stdio.h>

StartState::StartState(StateQueue* origin) {

    this->origin = origin;

    this->window = new RenderWindow("TDA-OH!", 800, 600);

    // Carga las texturas de los botones
    Texture* texture = loadTexture("assets/images/play_button.png");
    playButton.setTexture(texture);
    playButton.setPosition(219, 308);

    texture = loadTexture("assets/images/rules_button.png");
    rulesButton.setTexture(texture);
    rulesButton.setPosition(219, 396);

    texture = loadTexture("assets/images/quit_button.png");
    quitButton.setTexture(texture);
    quitButton.setPosition(219, 484);

    // boton y fondo de "¿Comó se juega?"
    texture = loadTexture("assets/images/elon.png");
    quitRulesButton.setTexture(texture);
    quitRulesButton.setPosition(744, 0);

    // "¿Comó se juega?"
    texture = loadTexture("assets/images/special_rules.png");
    rules.setTexture(texture);

    texture = loadTexture("assets/images/rules_backbround.png");
    rulesBackground.setTexture(texture);
    rules.setPosition((800 - rules.getSize().x)/2, 0);

    // Fondo
    texture = loadTexture("assets/images/background1.png");
    background.setTexture(texture);

    // Logo
    texture = loadTexture("assets/images/tdaoh_logo.png");
    title.setTexture(texture, false);
    title.setSize(513, 306);
    title.setPosition(144, 20);
}

StartState::~StartState() {
    delete this->window;

    destroyTexture(playButton.texure);
    destroyTexture(rulesButton.texure);
    destroyTexture(quitButton.texure);

    destroyTexture(background.getTexture());
    destroyTexture(title.getTexture());

    destroyTexture(quitRulesButton.texure);
    destroyTexture(rulesBackground.getTexture());
}

void StartState::update() {

    int x, y;
    unsigned int mouseState = SDL_GetMouseState(&x, &y);

    if (mouseState & SDL_BUTTON(SDL_BUTTON_LEFT)) {
        
        if (playButton.mouseIsOver(x, y) && !showRules) {
            State* s = new DuelState(origin);
            pushState(s);
            end();
        }

        if (rulesButton.mouseIsOver(x, y) && !showRules) {
            showRules = true;
        }

        if (quitRulesButton.mouseIsOver(x, y) && showRules) {
            showRules = false;
            rules.setPosition((800 - rules.getSize().x)/2, 0);
        }

        if (quitButton.mouseIsOver(x, y) && !showRules) {
            end();
        }
    }

    if (showRules)
        rulesInput();

    background.move(-0.8 * gDeltaTime, -0.8 * gDeltaTime);

    // Fondo movible
    if ( background.getPosition().x <= -80.0f) {
        background.setPosition(0, background.getPosition().y);
    }

    if ( background.getPosition().y <= -80.0f) {
        background.setPosition(background.getPosition().x, 0);
    }
}

void StartState::rulesInput() {
    const Uint8* keyStates = SDL_GetKeyboardState(NULL);
    if(keyStates[SDL_SCANCODE_UP] && rules.getPosition().y >= -(rules.getSize().y - 600)) {
        rules.move(0, -gDeltaTime);
    }

    if (keyStates[SDL_SCANCODE_DOWN] && rules.getPosition().y < 0) {
        rules.move(0, gDeltaTime);
    }
}

// Eventos de SDL
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

    draw(title);

    draw(playButton.sprite);
    draw(rulesButton.sprite);
    draw(quitButton.sprite);

    if (showRules){
        draw(rulesBackground);
        draw(quitRulesButton.sprite);
        draw(rules);
    }
}

void StartState::clear() {
    this->window->display();
    this->window->clear();
}