/*
    SchumakerTeam
    Hudson Schumaker
*/

#pragma once
#include "Component.h"
#include "../../gfx/Gfx.h"
#include "../../physics/Vec2.h"

class TextLabel final : public Component {
public:
    std::string fontName;
    SDL_Texture* label;
    bool isFixed;
    Vec2 position;
    std::string text;
    short size;
    SDL_Color color;
    int w = 0;
    int h = 0;

    TextLabel(const std::string fontName, bool isFixed, Vec2 position, std::string text, short size, SDL_Color color) {
        this->fontName = fontName;
        this->isFixed = isFixed;
        this->text = text;
        this->size = size;
        this->position = position;
        this->color = color;

        this->label = Gfx::getInstance()->createText(fontName, text, size, color);
        SDL_QueryTexture(label, NULL, NULL, &w, &h);
    }

    TextLabel(const std::string fontName, bool isFixed, float x, float y, std::string text, short size, SDL_Color color) {
        this->fontName = fontName;
        this->isFixed = isFixed;
        this->text = text;
        this->size = size;
        this->position = { x, y };
        this->color = color;

        this->label = Gfx::getInstance()->createText(fontName, text, size, color);
        SDL_QueryTexture(label, NULL, NULL, &w, &h);
    }

    void changeSize(short newSize) {
        this->label = Gfx::getInstance()->createText(fontName, text, newSize, color);
        SDL_QueryTexture(label, NULL, NULL, &w, &h);
    }

    void changeColor(SDL_Color newColor) {
        this->label = Gfx::getInstance()->createText(fontName, text, size, newColor);
    }

    void setOnCenter() {
        auto bounds = Gfx::getInstance()->getTextureSize(label);
        position.x = SCREEN_H_WIDTH - (bounds.x/2);
        position.y = SCREEN_H_HEIGHT - (bounds.y/2);
    }

    void setOnCenterX() {
        auto bounds = Gfx::getInstance()->getTextureSize(label);
        position.x = SCREEN_H_WIDTH - (bounds.x/2);
    }

    void setOnCenterY() {
        auto bounds = Gfx::getInstance()->getTextureSize(label);
        position.y = SCREEN_H_HEIGHT - (bounds.y/2);
    }

    ~TextLabel() = default;
};
