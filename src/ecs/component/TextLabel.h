/*
    Windows 10 - 11
    SchumakerTeam
    Hudson Schumaker
*/

#pragma once
#include "Component.h"
#include "../../physics/Vec2.h"

class TextLabel final : public Component {
public:
    Vec2 position;
    std::string text;
    SDL_Color color;
};
