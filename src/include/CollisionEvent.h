/*
    SchumakerTeam
    Hudson Schumaker
*/

#pragma once
#include "Event.h"
#include "Entity.h"

class CollisionEvent : public Event {
public:
    Entity* a;
    Entity* b;
    CollisionEvent(Entity* a, Entity* b) : a(a), b(b) {}
};
