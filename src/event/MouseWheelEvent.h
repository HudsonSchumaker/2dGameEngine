/*
	SchumakerTeam
	Hudson Schumaker
*/

#pragma once
#include "Event.h"

class MouseWheelEvent final : public Event {
public:
    int y;
    MouseWheelEvent(int y) : y(y) {}
};
