/*
	SchumakerTeam
	Hudson Schumaker
*/

#pragma once
#include "Event.h"
#include "Vec2.h"

class JoyPadLeftAxisEvent : public Event {
public:
	Vec2 axis;
	JoyPadLeftAxisEvent(Vec2 axis) : axis(axis) {}
};
