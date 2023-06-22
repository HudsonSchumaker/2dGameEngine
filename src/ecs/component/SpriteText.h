/*
	Dodoi Lab
	Dodoi Engine
	Hudson Schumaker
*/

#pragma once
#include "Component.h"
#include "../../gfx/Gfx.h"
#include "../../physics/Vec2.h"
#include "../../ecs/component/Transform.h"

class SpriteText final : public Component {
public:
	std::string fontName;
    SDL_Texture* label;
    bool isFixed;
    Vec2 offSet;
	Vec2 position;
    std::string text;
    short size;
    SDL_Color color;
    int w = 0;
    int h = 0;

	SpriteText(const std::string fontName, bool isFixed, float offsetX, float offsetY, std::string text, short size, SDL_Color color):
	SpriteText(fontName, isFixed, {offsetX, offsetY}, text, size, color) {}

	SpriteText(const std::string fontName, bool isFixed, Vec2 offSet, std::string text, short size, SDL_Color color) {
		this->fontName = fontName;
        this->isFixed = isFixed;
        this->text = text;
        this->size = size;
        this->offSet = offSet;
        this->color = color;

        this->label = Gfx::getInstance()->createText(fontName, text, size, color);
        SDL_QueryTexture(label, NULL, NULL, &w, &h);
	}
};