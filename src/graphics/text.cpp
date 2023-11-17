#include "graphics/text.h"

#include "graphics/render_window.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>

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
    if (this->texture != NULL) {
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
    if (need_update) {
        update_texture(target);
    }

    SDL_FRect rect;
    rect.x = get_position().x;
    rect.y = get_position().y;

    rect.w = size.x * get_scale().x;
    rect.h = size.y * get_scale().y;
    
    SDL_RenderCopyExF(target->get_renderer(), this->texture, NULL, &rect, this->rotation, NULL, SDL_FLIP_NONE);

}