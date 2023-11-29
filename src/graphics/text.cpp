#include "graphics/text.h"

#include "util.h"
#include "graphics/render_window.h"

#include <stdio.h>
#include <string.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

Text::~Text() {
    if (this->texture != nullptr) {
        SDL_DestroyTexture(this->texture);
    }
}

void Text::setFont(const char* filename) {
    this->needUpdate = true;
    this->fontDir = filename;
}

void Text::setSize(int size) {
    this->needUpdate = true;
    this->fontSize = size;
}

void Text::setText(const char* string) {
    this->needUpdate = true;
    this->text = string;
}

void Text::updateTexture(const RenderWindow* target) const {
    if (this->text == NULL) {
        return;
    }

    int size = this->fontSize * max(getScale().x, getScale().y);

    // Carga la fuente
    TTF_Font* font = TTF_OpenFont(this->fontDir, size);
    if (font == NULL) {
        error("No se pudo cargar la fuente%s\n", TTF_GetError());
    }

    // Carga la textura. Esta contiene el texto en la fuente deseada.
    SDL_Surface* surface = TTF_RenderUTF8_Blended_Wrapped(font, this->text, {this->color.a, this->color.g, this->color.b, this->color.a}, strlen(this->text) * size);
    this->texture = SDL_CreateTextureFromSurface(target->getRenderer(), surface);

    // Actualiza el tamaño
    SDL_QueryTexture(texture, NULL, NULL, &this->size.x, &this->size.y);

    // Cierra el archivo de la fuente
    TTF_CloseFont(font);
    this->needUpdate = false;
}

void Text::draw(const RenderWindow* target) const {

    // Rederisa de nuevo la textura si se necesita o si se cambio de 'target'
    if (this->needUpdate || this->lastRenderer != target->getRenderer()) {
        updateTexture(target);
    }

    SDL_FRect rect;
    rect.w = size.x * getScale().x;
    rect.h = size.y * getScale().y;

    // Calcular la posición centrada
    rect.x = getPosition().x - (rect.w - size.x) / 2.0f;
    rect.y = getPosition().y - (rect.h - size.y) / 2.0f;
    
    SDL_RenderCopyExF(target->getRenderer(), this->texture, NULL, &rect, this->rotation, NULL, SDL_FLIP_NONE);

    this->lastRenderer = target->getRenderer();
}

void Text::setScale(float x, float y) {
    this->scalar.x = x;
    this->scalar.y = y;
    this->needUpdate = true;
}

void Text::setScale(const Vector2& scale) {
    setScale(scale.y, scale.x);
}

void Text::setScale(float scale) {
    setScale(scale, scale);
}