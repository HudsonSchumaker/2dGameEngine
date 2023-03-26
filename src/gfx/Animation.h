/*
    SchumakerTeam
    Hudson Schumaker
*/

#pragma once
#include "../ecs/Entity.h"
#include "../ecs/component/Component.h"

class Animation final : public Component {
public:
    SDL_Texture* texture = nullptr;
    SDL_Point bounds;

    int startTime;
    bool flip = false;
    bool isLoop = true;
    bool isFixed = false;
    short layer = 1;
    short numFrames = 1;
    short currentFrame = 1;
    short frameSpeedRate = 1;
    
    Animation(const std::string& name, short numFrames, short frameSpeedRate, bool isLoop);
    Animation(const std::string& name, short numFrames, short frameSpeedRate, short layer, bool isLoop);
    ~Animation();

    static bool compareAsc(Entity* e1, Entity* e2);
    static bool compareDesc(Entity* e1, Entity* e2);
};