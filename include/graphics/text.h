#ifndef GRAPHICS_TEXT_H
#define GRAPHICS_TEXT_H

#include "graphics/drawable.h"
#include "graphics/transformable.h"
#include "graphics/texture.h"
#include "graphics/color.h"

class Text : public Drawable, public Transformable {

public:

    Text(const char* text = "Inserte Texto", const char* font = "assets/fonts/source_code_pro.ttf")
        : text(text), fontDir(font) {};

    virtual ~Text();

    /* Cambia el texto ha mostar */
    void setText(const char* string);

    /* Cambia la fuente a mostrar */
    void setFont(const char* filename);

    /* Cambia el tamaño de fuente */
    void setSize(int size);

    /* Cambia el color del texto */
    void setColor(Color color) { this->color = color; }

    void setScale(float x, float y) override;
    void setScale(const Vector2& scale) override;
    void setScale(const float scale) override;

private:

    /* Actualiza la textura donde se renderisa el texto */
    void updateTexture(const RenderWindow* target) const;
    virtual void draw(const RenderWindow* target) const override;

    const char* text;
    const char* fontDir;
    int fontSize = 12;
    Color color;

    // Ninguno ha de tener getters
    mutable Vector2i size;
    mutable Texture* texture = nullptr;
    mutable bool needUpdate = true;
    mutable SDL_Renderer* lastRenderer = nullptr;
};


#endif //GRAPHICS_TEXT_H