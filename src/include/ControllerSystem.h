/*
    SchumakerTeam
    Hudson Schumaker
*/

#pragma once
#include "System.h"
#include "KeyPressedEvent.h"
#include "KeyReleasedEvent.h"
#include "JoyPadLeftAxisEvent.h"

class ControllerSystem final : public System {
private:
    void subscribeToEvents();

public:
    ControllerSystem();
    ~ControllerSystem() = default;
        
    void onKeyPressed(KeyPressedEvent& event);
    void onKeyReleased(KeyReleasedEvent& event);
    void joypadLeftAxis(JoyPadLeftAxisEvent& event);
};