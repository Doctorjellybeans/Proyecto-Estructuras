#ifndef GRAPHICS_SPRITE_H
#define GRAPHICS_SPRITE_H

#include <SDL2/SDL.h>

#include "graphics/drawable.h"
#include "graphics/transformable.h"
#include "graphics/texture.h"

class Sprite : public Drawable, public Transformable {
public:

    Sprite() { create(0, 0, nullptr); }
    Sprite(int width, int height) { create(width, height, nullptr); }
    
    virtual ~Sprite() = default;

    void setSize(int width, int height);
    void setSize(const Vector2& size);

    Vector2 getSize() const { return this->size; }

    void setTexture(Texture* texture, bool change_size = true);
    Texture* getTexture() { return texture; }

    /* Revisa si contiene un puntoe en rectangulo que forma
    su posicion con su tamaño (ingnora la rotación)*/
    bool contains(float x, float y);
    
private:

    void create(int width, int height, Texture* texture);
    virtual void draw(const RenderWindow* target) const;
    Texture* texture;

    Vector2 size;
    SDL_Rect uv;
};

#endif // GRAPHICS_SPRITE_H