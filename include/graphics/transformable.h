#ifndef GRAPHICS_TRANSFORMABLE_H
#define GRAPHICS_TRANSFORMABLE_H

struct Vector2i {
    int x;
    int y;
};

struct Vector2 {
    float x;
    float y;
};

class Transformable {
public:

    Transformable();
    virtual ~Transformable() = default;

    void setPosition(float x, float y);
    void setPosition(const Vector2& position);
    Vector2 getPosition() const { return this->position; }

    void setRotation(float angle) { this->rotation = angle; }
    float getRotation() const     { return this->rotation;  }

    virtual void setScale(float x, float y);
    virtual void setScale(const Vector2& scale);
    virtual void setScale(const float scale);

    Vector2 getScale() const { return this->scalar; }

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