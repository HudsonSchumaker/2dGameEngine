/*
	SchumakerTeam
	Dodoi Engine
	Hudson Schumaker
*/

#pragma once
#include "Event.h"
#include "../ecs/Entity.h"

class MouseHoverEvent : public Event {
public:
    Entity* b;
    bool isInside;

    MouseHoverEvent(Entity* b, bool isInside) : b(b), isInside(isInside) {}
};
