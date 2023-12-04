#include "states/duel.h"

DuelState::DuelState(StateQueue* origin) {
    this->origin = origin;

    // Inicializa Ventanas
    window1 = new RenderWindow("TDA-OH! - Jugador1", 400, 400, 300);
    window2 = new RenderWindow("TDA-OH! - Jugador2", 400, 400, 800);

    this->textures = new TextureManager(window1, window2);

    // Inicializa Jugadores
    player1 = new Player(100, TDAType::STACK);
    player2 = new Player(100, TDAType::STACK);

    deck.fillDeck();
    for (int i = 0; i < 16 ; i++){
        player1->addCardToHand(deck);
        player2->addCardToHand(deck);
    }


    // Cartas Jugador 1
    Texture* texture = getTexture("assets/images/card.png", 1);
    Card* temp = player1->hand.first();
    while (temp != nullptr)
    {
        temp->sprite.setTexture(texture);
        temp->sprite.setPosition(0, 271);
        temp = player1->hand.next();
    }
    player1->hand.first();
    player1->hand.current()->sprite.setPosition(0, 211);

    // Cartas Jugador 2
    texture = getTexture("assets/images/card.png", 2);
    temp = player2->hand.first();
    while (temp != nullptr)
    {
        temp->sprite.setTexture(texture);
        temp->sprite.setPosition(0, 271);
        temp = player2->hand.next();
    }
    player2->hand.first();
    player2->hand.current()->sprite.setPosition(0, 211);
    
    // Fondos
    texture = getTexture("assets/images/player1_background.png", 1);
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

    // Consigue el input

    if (inputDelay1 <= 0) {
        Input(1);
    } else {
        inputDelay1 -= gDeltaTime;
    }

    if (inputDelay2 <= 0) {
        Input(2);
    } else {
        inputDelay2 -= gDeltaTime;
    }

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

// Input Jugador 1
void DuelState::Input(int value) {
    const Uint8* keyStates = SDL_GetKeyboardState(NULL);

    unsigned int rigth = 0;
    unsigned int left = 0;

    Player* player;
    if (value == 1) {
        player = player1;
        rigth = SDL_SCANCODE_W;
        left = SDL_SCANCODE_Q;

        inputDelay1 = 4;
    }
    else {
        player = player2;
        rigth = SDL_SCANCODE_P;
        left = SDL_SCANCODE_O;

        inputDelay2 = 4;
    }

    List<Card>& hand = player->hand;

    if(keyStates[rigth]) {
        Sprite& sprite = hand.current()->sprite;
        sprite.setPosition(sprite.getPosition().x, 271);

        hand.next();
        if(hand.current() == nullptr) {
            hand.last();
        }

        Sprite& sprite2 = hand.current()->sprite;
        sprite2.setPosition(sprite.getPosition().x, 211);

    }

    if (keyStates[left]) {
        Sprite& sprite = hand.current()->sprite;
        sprite.setPosition(sprite.getPosition().x, 271);

        hand.prev();
        if(hand.current() == nullptr) {
            hand.first();
        }

        Sprite& sprite2 = hand.current()->sprite;
        sprite2.setPosition(sprite.getPosition().x, 211);
    }
}


void DuelState::render() {
    draw(background1, 1);
    draw(background2, 2);

    drawCards(1);
    drawCards(2);
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

void DuelState::drawCards(int value) {

    Player* player;
    if (value == 1) {
        player = player1;
    }
    else {
        player = player2;
    }

    // El sprite del borde blanco
    Sprite white_border;
    Texture* texture = getTexture("assets/images/white_card.png", value);
    white_border.setTexture(texture);

    // referncia del la mano de jugador
    List<Card>& hand = player->hand;

    // guarda el 'current'
    Card* cur = hand.current();

    float offset = 320 / (hand.size());
    float posX = 0;

    // Dibuja las cartas de las lista
    // a excepcioón del current
    Card* temp = hand.first();
    while (temp != nullptr)
    {
        temp->sprite.setPosition(posX, temp->sprite.getPosition().y);

        if(cur != temp)
            draw(temp->sprite, value);
        posX += offset;

        temp = hand.next();
    }
    draw(cur->sprite, value);

    // Borde blanco
    white_border.setPosition(cur->sprite.getPosition());
    draw(white_border, value);

    // Devuelve la lista a su
    // antiguo 'current'
    temp = hand.first();
    while (cur != temp)
    {
        temp = hand.next();
    }
    
}