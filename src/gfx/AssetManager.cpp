/*
    SchumakerLab
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

void AssetManager::addTexture(const short assetId, const short value, const std::string& filePath) {
    SDL_Texture* texture = Gfx::getInstance()->loadTexture(filePath);

    std::pair pair = { value, texture };
    this->textures.emplace(assetId, pair);
}

SDL_Texture* AssetManager::getTexture(const short assetId) {
    return textures[assetId].second;
}

void AssetManager::clearAssets() {
    for (auto& texture : textures) {
        SDL_DestroyTexture(texture.second.second);
    }

    this->textures.clear();
}

void AssetManager::load() {
    //addTexture(MENU_BACKGROUND, 0, "data//menuBackground.png");

    std::cout << "done load texture" << std::endl;
}
