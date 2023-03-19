/*
    SchumakerLab
    SchumakerTeam
    Hudson Schumaker
*/

#pragma once
#include "../include/Common.h"

class AudioManager final {
private:
    inline static AudioManager* instance;
    std::map<short, Mix_Chunk*> sounds;

    AudioManager();
    ~AudioManager();

public:
    static AudioManager* getInstance();
    void load();
    void addSound(const short assetId, const std::string& filePath);
    void playSound(const short assetId);
    void clearAssets();

    static const short BACK = 0;
    static const short OK = 1;
};
