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
    short fontId;
    boolean isFixed;
    Vec2 position;
    std::string text;
    SDL_Color color;

    TextLabel(short fontId, boolean isFixed, Vec2 position, std::string text, SDL_Color color) {
        this->fontId = fontId;
        this->isFixed = isFixed;
        this->position = position;
        this->text = text;
        this->color = color;
    }

    ~TextLabel() = default;
};
