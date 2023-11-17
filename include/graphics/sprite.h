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

    void set_size(int width, int height);
    void set_size(const Vector2& size);

    Vector2 get_size() const { return this->size; }

    void set_texture(Texture* texture);

private:

    void create(int width, int height, Texture* texture);
    virtual void draw(const RenderWindow* target) const;

    Vector2 size;
    Texture* texture;
    SDL_Rect uv;
};

#endif // GRAPHICS_SPRITE_H