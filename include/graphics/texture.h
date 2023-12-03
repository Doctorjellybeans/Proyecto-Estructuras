#ifndef GRAPHICS_TEXTURE_H
#define GRAPHICS_TEXTURE_H

// Aliases para las texturas de SDL
#include <SDL2/SDL.h>
using Texture = SDL_Texture;

// Libera la memoria usada por una textura
inline void destroyTexture(Texture* texture) {
    SDL_DestroyTexture(texture);
} 
    
#endif // GRAPHICS_TEXTURE_H