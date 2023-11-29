#include "texture_manager.h"

#include <iostream>
#include "util.h"

Texture* TextureManager::get(const char* texture_path, int value) {


    Pair<Texture*, Texture*>* ptr = textureMap.search(texture_path);
    if (ptr == nullptr) {

        Texture* tex1 = this->win1->loadTexture(texture_path);
        Texture* tex2 = this->win2->loadTexture(texture_path);
        Pair<Texture*, Texture*>* pair = new Pair<Texture*, Texture*>(tex1, tex2);

        textureMap.insert(texture_path, pair);

        ptr = textureMap.search(texture_path);
        if(ptr == nullptr) {
            error("No se puedo cargar la textura en el mapa");
            return nullptr;
        }
    }

    if (value == 1){
        return ptr->key;
    } else {
        return ptr->value;
    }

    return nullptr; // error
}

TextureManager::~TextureManager() {

    Pair<Texture*, Texture*>* pair = textureMap.first();
    while (pair != nullptr) {
        destroyTexture(pair->key);
        destroyTexture(pair->value);
        delete pair;

        pair = textureMap.first();
    }
}