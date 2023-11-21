#include <stdio.h>

#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "graphics.h"
#include "application.h"

int main(int argc, char* args[]) {
    
    // Inicializa SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        printf("SDL2 no se pudo inicializar. %s\n", SDL_GetError());
    }

    if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG) {
        printf("SDL_image no se pudo inicializar. %s\n", IMG_GetError());
    }

    if (TTF_Init() != 0) {
        printf("SDL_ttf no se pudo inicializar. %s\n", TTF_GetError());
    }

    Application tdaoh;
    tdaoh.run();
    
    // Finaliza SDL
    SDL_Quit();

    return 0;
}