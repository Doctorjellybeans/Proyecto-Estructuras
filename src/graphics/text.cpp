#include "graphics/text.h"

#include "util.h"
#include "graphics/render_window.h"

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

Text::Text() {

    text = "Inserte Texto";
    font_dir = "assets/fonts/source_code_pro.ttf";

    font_size = 12;
    need_update = true;

    size.x = 0;
    size.y = 0;

    texture = NULL;
}

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
    TTF_Font* font = TTF_OpenFont(this->font_dir, this->font_size);
    if (font == NULL) {
        printf("error: %s\n", TTF_GetError());
    }

    SDL_Surface* surface = TTF_RenderText_Solid(font, this->text, {255, 255, 255, 255});
    this->texture = SDL_CreateTextureFromSurface(target->get_renderer(), surface);

    SDL_QueryTexture(texture, NULL, NULL, &size.x, &size.y);

    this->need_update = false;
    TTF_CloseFont(font);
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