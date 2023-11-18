#include "graphics/render_window.h"

#include "util.h"

#include <SDL2/SDL_image.h>
#include <stdio.h>

RenderWindow::RenderWindow(const char* title, int width, int height) {
    this->window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    this->renderer = SDL_CreateRenderer(this->window, -1, 0);

    SDL_RenderSetVSync(this->renderer, 1); // sincronización vertical

    this->is_closed = false;
}

RenderWindow::~RenderWindow() {
    SDL_DestroyWindow(this->window);
    SDL_DestroyRenderer(this->renderer);
}

void RenderWindow::close() {
    this->is_closed = true;
    this->~RenderWindow();
}

void RenderWindow::display() {
    SDL_RenderPresent(this->renderer);
}

void RenderWindow::clear() {
    SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 255);
    SDL_RenderClear(this->renderer);
}

Texture* RenderWindow::load_texture(const char* filename) {
    Texture* texture = IMG_LoadTexture(get_renderer(), filename);

    if (texture == NULL) {
        error("Error al cargar textura. %s", SDL_GetError());
    }

    return texture;
}

void RenderWindow::draw(const Drawable& drawable) const {
    drawable.draw(this);
}