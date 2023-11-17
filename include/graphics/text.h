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

private:

    void update_texture(const RenderWindow* target) const;
    virtual void draw(const RenderWindow* target) const;

    const char* text;
    const char* font_dir;
    int font_size;

    mutable Vector2i size;
    mutable bool need_update;
    mutable Texture* texture;

};


#endif //GRAPHICS_TEXT_H