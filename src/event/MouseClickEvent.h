/*
	SchumakerTeam
	Hudson Schumaker
*/

#pragma once
#include "Event.h"
#include "../core/MousePointer.h"


class MouseClickEvent final : public Event {
public:
    MousePointer pointer;
    MouseButton button;

    MouseClickEvent(MousePointer p) : pointer(p) {}
};
