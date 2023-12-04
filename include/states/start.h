#ifndef STATE_START_H
#define STATE_START_H

#include "state.h"
#include "graphics.h"

// Estado de la pantalla de titulo

class StartState : public State {

public:

    StartState(StateQueue* origin);
    ~StartState();

    // Metodos de State
    void update();
    void render();
    void clear();
    void pollEvents();

private:

    // structa botton para simplificar codigo
    struct Button {
        Sprite sprite;
        Texture* texure = nullptr;

        bool mouseIsOver(float x, float y) { return sprite.contains(x, y); }
        void setTexture(Texture* texture) { sprite.setTexture(texture); }
        void setPosition(float x, float y) { sprite.setPosition(x, y); }
    };

    void draw(Drawable& drawable) { this->window->draw(drawable); }
    Texture* loadTexture(const char* filename) { return window->loadTexture(filename); }
    void rulesInput();

    bool showRules = false;

    RenderWindow* window;

    Sprite background;
    Sprite rulesBackground;
    Sprite rules;


    Sprite title;
    Texture* titleTexture;

    Button playButton;
    Button rulesButton;
    Button quitButton;
    Button quitRulesButton;
};

#endif // STATE_START_H