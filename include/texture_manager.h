#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include "graphics.h"
#include "TDAs/map.h"


class TextureManager {

public:

    TextureManager(RenderWindow* win1, RenderWindow* win2) : win1(win1), win2(win2) {};
    ~TextureManager();

    Texture* get(const char* texture_path, int value);

private:

    Map<const char*, Pair<Texture*, Texture*>> textureMap;
    RenderWindow* win1;
    RenderWindow* win2;

};

#endif //TEXTURE_MANAGER_H