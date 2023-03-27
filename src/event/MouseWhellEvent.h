/*
	SchumakerTeam
	Hudson Schumaker
*/

#pragma once
#include "Event.h"

class MouseWhellEvent final : public Event {
public:
    int y;
    MouseWhellEvent(int y) : y(y) {}
};
