#ifndef GRAPHICS_SPRITE_H
#define GRAPHICS_SPRITE_H

#include <SDL2/SDL.h>

#include "graphics/drawable.h"
#include "graphics/transformable.h"
#include "graphics/texture.h"

class Sprite : public Drawable, public Transformable {
public:

    Sprite() { create(0, 0, NULL); }
    Sprite(int width, int height) { create(width, height, NULL); }
    
    virtual ~Sprite() = default;

    void setSize(int width, int height);
    void setSize(const Vector2& size);

    Vector2 getSize() const { return this->size; }

    void setTexture(Texture* texture);

    bool contains(float x, float y);

private:

    void create(int width, int height, Texture* texture);
    virtual void draw(const RenderWindow* target) const;

    Vector2 size;
    Texture* texture;
    SDL_Rect uv;
};

#endif // GRAPHICS_SPRITE_H