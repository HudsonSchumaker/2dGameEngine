/*
	Dodoi Lab
	Dodoi Engine
	Hudson Schumaker
*/

#pragma once
#include "../gfx/Color.h"
#include "../ecs/Entity.h"
#include "../physics/Dimension.h"
#include "../ecs/component/Component.h"

class Circle final : public Component {
public:
    int r = 0;
    short layer = 10;
    bool isFixed = false;
    SDL_Color color = Color::getWhite();

    Circle(): r(2) {}
    Circle(int radius) : r(radius) {}
    Circle(int radius, short layer) : r(radius), layer(layer) {}
    Circle(int radius, short layer, bool isFixed) : r(radius), layer(layer), isFixed(isFixed) {}
    Circle(int radius, short layer, bool isFixed, SDL_Color color) : r(radius), layer(layer), isFixed(isFixed), color(color) {}
    ~Circle() = default;

    Dimension getSize() const;

    static bool compareAsc(Entity* e1, Entity* e2);
	static bool compareDesc(Entity* e1, Entity* e2);
};
