#ifndef RENDER_WINDOW_H
#define RENDER_WINDOW_H

#include "graphics/drawable.h"
#include "graphics/texture.h"

#include <SDL2/SDL.h>

// Clase Ventana, es esencialmente
// un wrapper de la ventanas de SDL

class RenderWindow {
    friend Drawable;

public:

    RenderWindow(const char* title, int width, int height, int posX = SDL_WINDOWPOS_CENTERED, int posY = SDL_WINDOWPOS_CENTERED);
    ~RenderWindow();

    /* Cierra la ventana */
    void close();

    /* Revisa si la ventana esta abierta */
    bool isOpen() { return !this->_isClosed; };

    /* Dibuja un objeto */
    void draw(const Drawable& drawable) const;

    /* Muestra un fotograma */
    void display();

    /* Limpia un fotograma */
    void clear();

    /* Carga una textura */
    Texture* loadTexture(const char* filename);

    /* Consiguie el renderer de SDL*/
    SDL_Renderer* getRenderer() const { return _renderer; }

private:

    SDL_Renderer* _renderer;
    SDL_Window* _window;

    bool _isClosed = false;
};

#endif // RENDER_WINDOW_H