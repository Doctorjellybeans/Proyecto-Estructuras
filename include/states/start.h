#ifndef STATE_START_H
#define STATE_START_H

#include "state.h"
#include "graphics.h"

class StartState : public State {

public:

    StartState(StateQueue* origin);
    ~StartState();

    void update();
    void render();
    void clear();
    
    void pollEvents();

private:

    struct Button {
        Sprite sprite;
        Texture* texure = nullptr;

        bool isClicked(float x, float y) { return sprite.contains(x, y); }
        void setTexture(Texture* texture) { sprite.setTexture(texture); }
        void setPosition(float x, float y) { sprite.setPosition(x, y); }
    };

    void draw(Drawable& drawable) { this->window->draw(drawable); }

    RenderWindow* window;
    Button playButton;
    Button rulesButton;
    Button quitButton;

    Sprite background;
    Texture* backgroundTexture;
};

#endif // STATE_START_H