#ifndef STATES_DUEL_H
#define STATES_DUEL_H

#include "state.h"
#include "graphics.h"
#include "texture_manager.h"


class DuelState : public State {

public:

    DuelState(StateQueue* origin);
    ~DuelState();

    void update();
    void render();
    void clear();

    void pollEvents();

private:

    Texture* getTexture(const char* texture_path, int value) { return textures->get(texture_path, value); }
    void draw(const Drawable& drawable, int value) const;

    TextureManager* textures;

    RenderWindow* window1;
    RenderWindow* window2;

    Sprite sprite1;
    Sprite sprite2;

    Texture* tex1;
    Texture* tex2;

};


#endif //STATES_DUEL_H