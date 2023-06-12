/*
	SchumakerTeam
	Dodoi Engine
	Hudson Schumaker
*/

#pragma once
#include "Event.h"
#include "../core/MousePointer.h"


class MouseClickEvent final : public Event {
public:
    MousePointer pointer;

    MouseClickEvent(MousePointer p) : pointer(p) {}
};
