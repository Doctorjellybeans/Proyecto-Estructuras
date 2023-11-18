#ifndef GRAPHICS_TEXT_H
#define GRAPHICS_TEXT_H

#include "graphics/drawable.h"
#include "graphics/transformable.h"
#include "graphics/texture.h"
#include "graphics/color.h"

class Text : public Drawable, public Transformable {

public:

    Text(const char* text = "Inserte Texto", const char* font = "assets/fonts/source_code_pro.ttf")
        : text(text), font_dir(font) {};

    virtual ~Text();

    /* Cambia el texto ha mostar */
    void set_text(const char* string);

    /* Cambia la fuente a mostrar */
    void set_font(const char* filename);

    /* Cambia el tamaño de fuente */
    void set_size(int size);

    /* Cambia el color del texto */
    void set_color(Color color) { this->color = color; }

    void set_scale(float x, float y) override;
    void set_scale(const Vector2& scale) override;
    void set_scale(const float scale) override;

private:

    /* Actualiza la textura donde se renderisa el texto */
    void update_texture(const RenderWindow* target) const;
    virtual void draw(const RenderWindow* target) const override;

    const char* text;
    const char* font_dir;
    int font_size = 12;
    Color color;

    // Ninguno ha de tener getters
    mutable Vector2i size;
    mutable Texture* texture = nullptr;
    mutable bool need_update = true;
    mutable SDL_Renderer* last_renderer = nullptr;
};


#endif //GRAPHICS_TEXT_H