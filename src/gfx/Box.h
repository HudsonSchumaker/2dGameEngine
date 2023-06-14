/*
	Dodoi Lab
	Dodoi Engine
	Hudson Schumaker
*/

#pragma once
#include "../ecs/Entity.h"
#include "../ecs/component/Component.h"
#include "../physics/Dimension.h"

class Box final : public Component {
public:
    int w = 0;
    int h = 0;
    short layer = 10;
    bool isFixed = false;
    
    Box();
    Box(int w, int h);
    Box(int w, int h, short layer);
    Box(int w, int h, short layer, bool isFixed);
    ~Box() = default;

    void setOnCenter();
	void setOnCenterX();
	void setOnCenterY();
    Dimension getSize() const;

	static bool compareAsc(Entity* e1, Entity* e2);
	static bool compareDesc(Entity* e1, Entity* e2);
};
