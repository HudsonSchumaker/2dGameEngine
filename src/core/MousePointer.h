/*
	SchumakerTeam
	Hudson Schumaker
*/

#pragma once
#include "../include/Common.h"

class MousePointer final {
public:
    int x, y;
    int w, h;

    MousePointer() {
        x = 0;
        y = 0;
        w = 2;
        h = 2;
    }

    MousePointer(int x, int y, int w, int h) : x(x), y(y), w(w), h(h) {}
    ~MousePointer() = default;

    SDL_Rect getBounds() const {
        return SDL_Rect { x, y, w, h };
    }
};
