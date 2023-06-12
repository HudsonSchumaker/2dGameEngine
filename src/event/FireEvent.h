/*
	SchumakerTeam
	Dodoi Engine
	Hudson Schumaker
*/

#pragma once
#include "Event.h"
#include "../ecs/Tag.h"

class FireEvent final : public Event {
public:
	Tag tag;
	FireEvent(Tag tag) : tag(tag) {}
};
