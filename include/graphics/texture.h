#ifndef GRAPHICS_TEXTURE_H
#define GRAPHICS_TEXTURE_H

#include <SDL2/SDL.h>
using Texture = SDL_Texture;

inline void destroyTexture(Texture* texture) {
    SDL_DestroyTexture(texture);
} 
    

#endif // GRAPHICS_TEXTURE_H