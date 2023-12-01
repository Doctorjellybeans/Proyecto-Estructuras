#ifndef GRAPHICS_DRAWABLE_H
#define GRAPHICS_DRAWABLE_H

class RenderWindow;


// Clase abstracta para objetos dibujables
class Drawable {
    friend RenderWindow;

protected:

    Drawable() = default;
    virtual ~Drawable() = default;
    
    virtual void draw(const RenderWindow* target) const = 0;
};

#endif