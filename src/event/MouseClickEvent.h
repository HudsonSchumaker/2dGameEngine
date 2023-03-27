/*
	SchumakerTeam
	Hudson Schumaker
*/

#pragma once
#include "Event.h"


enum class MouseButton {
	LEFT,
	RIGHT,
};


class MouseClickEvent final : Event {
public:
    int x, y;
    MouseButton button;

    MouseClickEvent(int x, int y, MouseButton b) : x(x), y(y), button(b) {}
};