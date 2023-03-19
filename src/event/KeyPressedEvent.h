/*
    Windows 10 - 11
    SchumakerTeam
    Hudson Schumaker
*/

#pragma once
#include "Event.h"

class KeyPressedEvent : public Event {
public:
    SDL_Keycode symbol;
    KeyPressedEvent(SDL_Keycode symbol) : symbol(symbol) {}
};