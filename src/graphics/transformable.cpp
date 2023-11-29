#include "graphics/transformable.h"

Transformable::Transformable() {
    this->position.x = 0;
    this->position.y = 0;
    this->scalar.x = 1;
    this->scalar.y = 1;
    this->rotation = 0;
}

void Transformable::setPosition(float x, float y) {
    this->position.x = x;
    this->position.y = y;
}

void Transformable::setPosition(const Vector2& position) {
    this->position = position;
}

void Transformable::move(float x, float y) {
    setPosition(this->position.x + x, this->position.y + y);
}

void Transformable::move(const Vector2& offset) {
    setPosition(this->position.x + offset.x, this->position.y + offset.y);
}

void Transformable::setScale(float x, float y) {
    this->scalar.x = x;
    this->scalar.y = y;
}

void Transformable::setScale(const Vector2& scale) {
    setScale(scale.y, scale.x);
}

void Transformable::setScale(float scale) {
    setScale(scale, scale);
}

void Transformable::scale(float x, float y) {
    setScale(this->scalar.x * x, this->scalar.y * y);
}

void Transformable::scale(const Vector2& scale) {
    setScale(this->scalar.x * scale.x, this->scalar.y * scale.y);
}

void Transformable::scale(float scale) {
    setScale(this->scalar.x * scale, this->scalar.y * scale);
}