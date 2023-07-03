/*
	Dodoi Lab
	Dodoi Engine
	Hudson Schumaker
*/

#pragma once
#include "System.h"
#include "../../event/EventBus.h"

class ProjectileEmitSystem final : public System {
private:
    void subscribeToEvents();

public:
    ProjectileEmitSystem();
    ~ProjectileEmitSystem() = default;
    void onFire(FireEvent& event);
};
