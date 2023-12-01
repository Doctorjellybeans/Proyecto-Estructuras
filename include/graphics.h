#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "graphics/render_window.h"
#include "graphics/texture.h"
#include "graphics/sprite.h"
#include "graphics/text.h"

// Global del mal.
// Ya que es inline no se tiene que "re-declarar" como con 'static'
inline float gDeltaTime = 0.0f;

#endif // GRAPHICS_H