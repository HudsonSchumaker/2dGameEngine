/*
	Dodoi Lab
	Dodoi Engine
	Hudson Schumaker
*/

#pragma once
#include "../gfx/Color.h"
#include "../ecs/Entity.h"
#include "../physics/Vec2.h"
#include "../physics/Dimension.h"
#include "../ecs/component/Component.h"

class Line final : public Component {
public:
    Vec2 a;
    Vec2 b;
    short layer = 10;
    bool isFixed = false;
    SDL_Color color =  Color::getWhite();

    Line(Vec2 a, Vec2 b) : a(a), b(b) {}
    Line(Vec2 a, Vec2 b, bool isFixed) : a(a), b(b), isFixed(isFixed) {}
    Line(Vec2 a, Vec2 b, bool isFixed, SDL_Color color) : a(a), b(b), isFixed(isFixed), color(color) {}
    ~Line() = default;

    Dimension getSize() const;
    static bool compareAsc(Entity* e1, Entity* e2);
    static bool compareDesc(Entity* e1, Entity* e2);
};
