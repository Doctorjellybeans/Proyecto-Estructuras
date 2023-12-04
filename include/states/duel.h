#ifndef STATES_DUEL_H
#define STATES_DUEL_H

#include "state.h"
#include "graphics.h"
#include "texture_manager.h"

#include "TDA-Oh/player.h"
#include "TDA-Oh/deck.h"

// Estado de duelo, aqui ocurre el juego en si
class DuelState : public State {
public:

    DuelState(StateQueue* origin);
    ~DuelState();

    // Metodos de State
    void update();
    void render();
    void clear();
    void pollEvents();

    Player* player1;
    Player* player2;

    Deck deck;

private:

    Texture* getTexture(const char* texture_path, int value) { return textures->get(texture_path, value); }

    void draw(const Drawable& drawable, int value) const;
    void drawCards(int value);

    void Input(int value);

    TextureManager* textures;

    RenderWindow* window1;
    RenderWindow* window2;

    Sprite background1;
    Sprite background2;

    float inputDelay1 = 0;
    float inputDelay2 = 0;

    bool player1turn = true;
};


#endif //STATES_DUEL_H