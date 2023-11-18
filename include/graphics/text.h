#ifndef GRAPHICS_TEXT_H
#define GRAPHICS_TEXT_H

#include "graphics/drawable.h"
#include "graphics/transformable.h"
#include "texture.h"

class Text : public Drawable, public Transformable {

public:

    Text();
    virtual ~Text();

    void set_text(const char* string);
    void set_font(const char* filename);
    void set_size(int size);

    void set_scale(float x, float y) override;
    void set_scale(const Vector2& scale) override;
    void set_scale(const float scale) override;


private:

    void update_texture(const RenderWindow* target) const;
    virtual void draw(const RenderWindow* target) const override;

    const char* text;
    const char* font_dir;
    int font_size;

    // Ninguno ha de tener getters
    mutable Vector2i size;
    mutable Texture* texture = nullptr;
    mutable bool need_update = true;
    mutable SDL_Renderer* last_renderer = nullptr;
};


#endif //GRAPHICS_TEXT_H