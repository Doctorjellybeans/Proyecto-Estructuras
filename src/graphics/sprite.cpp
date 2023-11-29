#include "graphics/sprite.h"

#include <stdio.h>
#include <SDL2/SDL.h>
#include "graphics/render_window.h"

void Sprite::create(int width, int height, SDL_Texture* texture) {
    setSize(width, height);
    this->texture = texture;

}

void Sprite::setSize(int width, int height) {
    this->size.x = width;
    this->size.y = height;
}

void Sprite::setSize(const Vector2& size) {
    this->size = size;
}

void Sprite::setTexture(Texture* texture) {
    int width, height;
    
    // Consigue el tamaño de la textura
    SDL_QueryTexture(texture, NULL, NULL, &width, &height);

    this->texture = texture;
    setSize(width, height);
}

void Sprite::draw(const RenderWindow* target) const {
    SDL_FRect rect;
    rect.w = getSize().x * getScale().x;
    rect.h = getSize().y * getScale().y;

    // Calcular la posición centrada
    rect.x = getPosition().x - (rect.w - getSize().x) / 2.0f;
    rect.y = getPosition().y - (rect.h - getSize().y) / 2.0f;
    
    SDL_RenderCopyExF(target->getRenderer(), this->texture, NULL, &rect, rotation, NULL, SDL_FLIP_NONE);
}

bool Sprite::contains(float x, float y) {
    return this->position.x <= x &&  this->position.x + this->size.x >= x &&
    this->position.y <= y &&  this->position.y + this->size.y >= y;
}
