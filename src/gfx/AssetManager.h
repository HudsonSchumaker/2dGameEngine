/*
    SchumakerLab
    SchumakerTeam
    Hudson Schumaker
*/

#pragma once
#include "../include/Common.h"

using asset_t = std::map<short, std::pair<short, SDL_Texture*>>;

class AssetManager final {
private:
    inline static AssetManager* instance;
    asset_t textures;

    AssetManager();
    ~AssetManager();

public:
    static AssetManager* getInstance();
    void load();
    void addTexture(const short assetId, const short value, const std::string& filePath);
    SDL_Texture* getTexture(const short assetId);
    void clearAssets();

    static const short MENU_BACKGROUND = 0;
};