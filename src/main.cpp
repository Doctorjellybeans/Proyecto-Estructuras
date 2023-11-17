#include <stdio.h>

#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "graphics.h"

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

    RenderWindow window("Ventana", 800, 600);
    Texture* texture = window.load_texture("assets/pucv.png");

    Sprite sprite;
    sprite.set_position(280, 200);
    sprite.set_texture(texture);

    Text hello_world;
    hello_world.set_text("Hola Mundo");
    hello_world.set_size(40);
    hello_world.set_position(40, 80);

    SDL_Event event;
    while (window.is_open())
    {
        while(SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                window.close();
                break;

            }
        }

        /* Actualizar */
        sprite.rotate(3);
        sprite.scale(1.005);
        
        /* Dibujar */
        window.draw(sprite);
        window.draw(hello_world);

        window.display();
        window.clear();
    }

    SDL_DestroyTexture(texture);
    
    // Finaliza SDL
    SDL_Quit();

    return 0;
}