/*
	SchumakerTeam
	Dodoi Engine
	Hudson Schumaker
*/

#pragma once
#include "../include/Common.h"

using texture_t = std::map<std::string, std::pair<short, SDL_Texture*>>;

class AssetManager final {
private:
    inline static AssetManager* instance;
    texture_t textures;

    AssetManager();
    ~AssetManager();

public:
    static AssetManager* getInstance();
    void load();
    void addTexture(const std::string& name, const short value, const std::string& filePath);
    SDL_Texture* getTexture(const std::string& name);
    int textureCount() const; 
    void clearAssets();
};