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
private:
    int r = 0;
public:
    short layer = 10;
    float side = 0.0f;
    bool isFixed = false;
    bool isDashed = false;
    short dashLength = 8;
    SDL_Color color = Color::getWhite();

    Circle(): r(2) { sideCalculation(); }
    Circle(int radius) : r(radius) { sideCalculation(); }
    Circle(int radius, short layer) : r(radius), layer(layer) { sideCalculation(); }
    Circle(int radius, short layer, bool isFixed) : r(radius), layer(layer), isFixed(isFixed) { sideCalculation(); }
    Circle(int radius, short layer, bool isFixed, SDL_Color color) : r(radius), layer(layer), isFixed(isFixed), color(color) { sideCalculation(); }
    Circle(int radius, short layer, bool isFixed, short dashLength, SDL_Color color) : r(radius), layer(layer), isFixed(isFixed), dashLength(dashLength) ,color(color) { sideCalculation(); }
    ~Circle() = default;

    void sideCalculation();
    int getRadius() const { return r; }
    void setRadius(int radius) { r = radius; sideCalculation(); }
    Dimension getSize() const;
    static bool compareAsc(Entity* e1, Entity* e2);
	static bool compareDesc(Entity* e1, Entity* e2);
};
