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
    addTexture(BFISH_SS, 0, "data/images/bfishssheet.png");
    addTexture(SUBEN_SS, 0, "data/images/subenssheet.png");
    addTexture(PLAYER_MOVE_SS, 0, "data/images/playermovess.png");
    addTexture(PLAYER_SHOOT_SS, 0, "data/images/playershootss.png");
    addTexture(SEA, 0, "data/images/sea.png");
    addTexture(PLAYER_C_MOVE_SS, 0, "data/images/sub2cmove.png");
    addTexture(PLAYER_C_SHOOT_SS, 0, "data/images/sub2cshoot.png");
    addTexture(BULLET_1, 0, "data/images/cshoot2.png");
    addTexture(TILES, 0, "data/images/tilesheet10.png");
    addTexture(BLOCK500, 0, "data/images/bloco500.png");

    std::cout << "done load texture" << std::endl;
}
