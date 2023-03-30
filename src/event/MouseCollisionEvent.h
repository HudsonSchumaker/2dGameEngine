/*
    SchumakerTeam
    Hudson Schumaker
*/

#pragma once
#include "Event.h"
#include "../ecs/Entity.h"

class MouseCollisionEvent : public Event {
public:
    Entity* a;
    int x = 0, y = 0;

    MouseCollisionEvent(Entity* a, int x, int y) : a(a), x(x), y(y) {}
};
