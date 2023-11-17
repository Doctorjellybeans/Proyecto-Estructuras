#ifndef GRAPHICS_TRANSFORMABLE_H
#define GRAPHICS_TRANSFORMABLE_H

struct Vector2 {
    float x;
    float y;
};

class Transformable {

public:

    Transformable();
    virtual ~Transformable() = default;

    void set_position(float x, float y);
    void set_position(const Vector2& position);
    Vector2 get_position() const { return this->position; }

    void set_rotation(float angle) { this->rotation = angle; }
    float get_rotation() const     { return this->rotation;  }

    void set_scale(float x, float y);
    void set_scale(const Vector2& scale);
    void set_scale(const float scale);
    Vector2 get_scale() const { return this->scalar; }

    void move(float x, float y);
    void move(const Vector2& offset);

    void rotate(float angle) { this->rotation += angle; }

    void scale(float x, float y);
    void scale(const Vector2& scale);
    void scale(float scale);

protected:

    Vector2 position;
    Vector2 scalar;
    float rotation;

};

#endif // GRAPHICS_TRANSFORMABLE_H