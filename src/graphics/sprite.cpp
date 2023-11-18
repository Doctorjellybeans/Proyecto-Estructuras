#include "graphics/sprite.h"

#include <stdio.h>
#include <SDL2/SDL.h>
#include "graphics/render_window.h"

void Sprite::create(int width, int height, SDL_Texture* texture) {
    set_size(width, height);
    this->texture = texture;

}

void Sprite::set_size(int width, int height) {
    this->size.x = width;
    this->size.y = height;
}

void Sprite::set_size(const Vector2& size) {
    this->size = size;
}

void Sprite::set_texture(Texture* texture) {
    int width, height;
    
    // Consigue el tamaño de la textura
    SDL_QueryTexture(texture, NULL, NULL, &width, &height);

    this->texture = texture;
    set_size(width, height);
}

void Sprite::draw(const RenderWindow* target) const {
    SDL_FRect rect;
    rect.w = get_size().x * get_scale().x;
    rect.h = get_size().y * get_scale().y;

    // Calcular la posición centrada
    rect.x = get_position().x - (rect.w - get_size().x) / 2.0f;
    rect.y = get_position().y - (rect.h - get_size().y) / 2.0f;
    
    SDL_RenderCopyExF(target->get_renderer(), this->texture, NULL, &rect, rotation, NULL, SDL_FLIP_NONE);
}