/*
	Dodoi Lab
	Dodoi Engine
	Hudson Schumaker
*/

#pragma once
#include "System.h"
#include "../../event/MouseHoverEvent.h"

class GuiUpdateSystem final : public System {
private:
    void subscribeToEvents();

public:
    GuiUpdateSystem();
    ~GuiUpdateSystem() = default;

    void onHover(MouseHoverEvent& event);
};
