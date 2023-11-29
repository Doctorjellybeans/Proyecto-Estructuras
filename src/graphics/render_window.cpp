#include "graphics/render_window.h"

#include "util.h"

#include <SDL2/SDL_image.h>
#include <stdio.h>

RenderWindow::RenderWindow(const char* title, int width, int height, int posX, int posY) {
    this->_window = SDL_CreateWindow(title, posX, posY, width, height, SDL_WINDOW_SHOWN);
    this->_renderer = SDL_CreateRenderer(_window, -1, 0);

    SDL_RenderSetVSync(this->_renderer, 1); // sincronización vertical
}

RenderWindow::~RenderWindow() {
    SDL_DestroyWindow(_window);
    SDL_DestroyRenderer(_renderer);
}

void RenderWindow::close() {
    _isClosed = true;
    this->~RenderWindow();
}

void RenderWindow::display() {
    SDL_RenderPresent(_renderer);
}

void RenderWindow::clear() {
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
    SDL_RenderClear(_renderer);
}

Texture* RenderWindow::loadTexture(const char* filename) {
    Texture* texture = IMG_LoadTexture(getRenderer(), filename);

    if (texture == NULL) {
        error("No se pudo cargar textura. %s", SDL_GetError());
    }

    return texture;
}

void RenderWindow::draw(const Drawable& drawable) const {
    drawable.draw(this);
}