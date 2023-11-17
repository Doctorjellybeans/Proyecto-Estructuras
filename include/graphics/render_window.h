#ifndef RENDER_WINDOW_H
#define RENDER_WINDOW_H

#include "graphics/drawable.h"
#include "graphics/texture.h"

#include <SDL2/SDL.h>

class RenderWindow {
    friend Drawable;

public:

    RenderWindow(const char* title, int width, int height);
    ~RenderWindow();

    /* Cierra la ventana */
    void close();

    /* Revisa si la ventana esta abierta */
    bool is_open() { return !this->is_closed; };

    /* Muestra un fotograma */
    void display();

    /* Limpia un fotograma */
    void clear();

    /* Dibuja un objeto */
    void draw(const Drawable& drawable) const;
    Texture* load_texture(const char* filename);
    SDL_Renderer* get_renderer() const { return this->renderer; }

private:

    SDL_Renderer* renderer;
    SDL_Window* window;

    bool is_closed;
};

#endif // RENDER_WINDOW_H