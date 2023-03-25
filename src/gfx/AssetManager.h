/*
    Windows 10 - 11
    SchumakerTeam
    Hudson Schumaker
*/

#pragma once
#include "../include/Common.h"

using texture_t = std::map<short, std::pair<short, SDL_Texture*>>;
using font_t = std::map<std::string, std::pair<short, TTF_Font*>>;

class AssetManager final {
private:
    inline static AssetManager* instance;
    texture_t textures;
    font_t fonts;

    AssetManager();
    ~AssetManager();

public:
    static AssetManager* getInstance();
    void load();
    void addTexture(const short assetId, const short value, const std::string& filePath);
    SDL_Texture* getTexture(const short assetId);
    void clearAssets();

    static const short MENU_BACKGROUND = 0;
    static const short BFISH_SS = 1;
    static const short SUBEN_SS = 2;
    static const short PLAYER_MOVE_SS = 3;
    static const short PLAYER_SHOOT_SS = 4;
    static const short SEA = 5;
    static const short PLAYER_C_MOVE_SS = 6;
    static const short PLAYER_C_SHOOT_SS = 7;
    static const short BULLET_1 = 8;
    static const short TILES = 9;
    static const short BLOCK500 = 10;
};