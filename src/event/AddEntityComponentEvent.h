/*
	SchumakerTeam
	Dodoi Engine
	Hudson Schumaker
*/

#pragma once
#include "Event.h"
#include "../ecs/Entity.h"
#include "../ecs/component/Component.h"

class AddEntityComponentEvent final : public Event {
public:
    Entity* entity;
    Component* component;

    AddEntityComponentEvent(* e, Component* c) : entity(e), component(c){}
};