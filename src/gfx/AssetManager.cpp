/*
    SchumakerTeam
    Hudson Schumaker
*/

#include "Gfx.h"
#include "AssetManager.h"

AssetManager::AssetManager() {}
AssetManager::~AssetManager() {
    clearAssets();
}

AssetManager* AssetManager::getInstance() {
    if (instance == nullptr) {
        instance = new AssetManager();
    }

    return instance;
}

void AssetManager::addTexture(const std::string& name, const short value, const std::string& filePath) {
    SDL_Texture* texture = Gfx::getInstance()->loadTexture(filePath);

    std::pair pair = { value, texture };
    this->textures.emplace(name, pair);
}

SDL_Texture* AssetManager::getTexture(const std::string& name) {
    return textures[name].second;
}

void AssetManager::clearAssets() {
    for (auto& texture : textures) {
        SDL_DestroyTexture(texture.second.second);
    }

    this->textures.clear();
}

void AssetManager::load() {
   

    std::cout << "done load texture" << std::endl;
}
