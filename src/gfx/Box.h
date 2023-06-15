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

class Box final : public Component {
public:
    int w = 0;
    int h = 0;
    short layer = 10;
    bool isFixed = false;
    SDL_Color color = Color::getWhite();
    
    Box();
    Box(int w, int h);
    Box(int w, int h, short layer);
    Box(int w, int h, short layer, bool isFixed);
    Box(int w, int h, short layer, bool isFixed, SDL_Color color);
    ~Box() = default;

    void setOnCenter();
	void setOnCenterX();
	void setOnCenterY();
    Dimension getSize() const;

	static bool compareAsc(Entity* e1, Entity* e2);
	static bool compareDesc(Entity* e1, Entity* e2);
};
