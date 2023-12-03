#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include "graphics.h"
#include "TDAs/map.h"

// Un mapa de texturas que genera una
// para cada pantalla del duelo
// solo se debe usar para el estado de duelo
class TextureManager {

public:

    TextureManager(RenderWindow* win1, RenderWindow* win2) : win1(win1), win2(win2) {};
    ~TextureManager();

    // Consigue una textura, en el caso de no existir la genera
    // value es para que ventana es esa textura
    Texture* get(const char* texture_path, int value);

private:

    Map<const char*, Pair<Texture*, Texture*>> textureMap;
    RenderWindow* win1;
    RenderWindow* win2;

};

#endif //TEXTURE_MANAGER_H