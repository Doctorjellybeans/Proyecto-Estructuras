#include "graphics/transformable.h"

Transformable::Transformable() {
    this->position.x = 0;
    this->position.y = 0;
    this->scalar.x = 1;
    this->scalar.y = 1;
    this->rotation = 0;
}

void Transformable::set_position(float x, float y) {
    this->position.x = x;
    this->position.y = y;
}

void Transformable::set_position(const Vector2& position) {
    this->position = position;
}

void Transformable::move(float x, float y) {
    set_position(this->position.x + x, this->position.y + y);
}

void Transformable::move(const Vector2& offset) {
    set_position(this->position.x + offset.x, this->position.y + offset.y);
}

void Transformable::set_scale(float x, float y) {
    this->scalar.x = x;
    this->scalar.y = y;
}

void Transformable::set_scale(const Vector2& scale) {
    this->scalar = scale;
}

void Transformable::set_scale(float scale) {
    this->scalar.x = scale;
    this->scalar.y = scale;
}

void Transformable::scale(float x, float y) {
    set_scale(this->scalar.x * x, this->scalar.y * y);
}

void Transformable::scale(const Vector2& scale) {
    set_scale(this->scalar.x * scale.x, this->scalar.y * scale.y);
}

void Transformable::scale(float scale) {
    set_scale(this->scalar.x * scale, this->scalar.y * scale);
}