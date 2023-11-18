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

void Text::set_font(const char* filename) {
    need_update = true;
    this->font_dir = filename;
}

void Text::set_size(int size) {
    this->need_update = true;
    this->font_size = size;
}

void Text::set_text(const char* string) {
    this->need_update = true;
    this->text = string;
}

void Text::update_texture(const RenderWindow* target) const {
    if (this->text == NULL) {
        return;
    }

    int size = this->font_size * max(get_scale().x, get_scale().y);

    // Carga la fuente
    TTF_Font* font = TTF_OpenFont(this->font_dir, size);
    if (font == NULL) {
        error("No se pudo cargar la fuente%s\n", TTF_GetError());
    }

    // Carga la textura. Esta contiene el texto en la fuente deseada.
    SDL_Surface* surface = TTF_RenderUTF8_Blended_Wrapped(font, this->text, {this->color.a, this->color.g, this->color.b, this->color.a}, strlen(this->text) * size);
    this->texture = SDL_CreateTextureFromSurface(target->get_renderer(), surface);

    // Actualiza el tamaño
    SDL_QueryTexture(texture, NULL, NULL, &this->size.x, &this->size.y);

    // Cierra el archivo de la fuente
    TTF_CloseFont(font);
    this->need_update = false;
}

void Text::draw(const RenderWindow* target) const {

    // Rederisa de nuevo la textura si se necesita o si se cambio de 'target'
    if (need_update || this->last_renderer != target->get_renderer()) {
        update_texture(target);
    }

    SDL_FRect rect;
    rect.w = size.x * get_scale().x;
    rect.h = size.y * get_scale().y;

    // Calcular la posición centrada
    rect.x = get_position().x - (rect.w - size.x) / 2.0f;
    rect.y = get_position().y - (rect.h - size.y) / 2.0f;
    
    SDL_RenderCopyExF(target->get_renderer(), this->texture, NULL, &rect, this->rotation, NULL, SDL_FLIP_NONE);

    this->last_renderer = target->get_renderer();
}

void Text::set_scale(float x, float y) {
    this->scalar.x = x;
    this->scalar.y = y;
    need_update = true;
}

void Text::set_scale(const Vector2& scale) {
    set_scale(scale.y, scale.x);
}

void Text::set_scale(float scale) {
    set_scale(scale, scale);
}