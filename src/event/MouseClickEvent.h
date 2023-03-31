/*
	SchumakerTeam
	Hudson Schumaker
*/

#pragma once
#include "Event.h"
#include "../core/MousePointer.h"

enum class MouseButton {
	LEFT,
	RIGHT,
};


class MouseClickEvent final : public Event {
public:
    MousePointer pointer;
    MouseButton button;

    MouseClickEvent(MousePointer p, MouseButton b) : pointer(p), button(b) {}
};
