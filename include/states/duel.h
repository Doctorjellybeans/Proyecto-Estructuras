#ifndef STATES_DUEL_H
#define STATES_DUEL_H

#include "state.h"
#include "graphics.h"
#include "texture_manager.h"

#include "TDA-Oh/player.h"

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

    Player* p1;
    Player* p2;

private:

    Texture* getTexture(const char* texture_path, int value) { return textures->get(texture_path, value); }
    void draw(const Drawable& drawable, int value) const;

    TextureManager* textures;

    RenderWindow* window1;
    RenderWindow* window2;

    Text text1;
    Text text2;

};


#endif //STATES_DUEL_H