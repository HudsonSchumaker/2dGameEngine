/*
    Windows 10 - 11
    SchumakerTeam
    Hudson Schumaker
*/

#pragma once
#include "System.h"
#include "../../event/FireEvent.h"

class ProjectileEmitSystem final : public System {
private:
    void subscribeToEvents();

public:
    ProjectileEmitSystem();
    ~ProjectileEmitSystem() = default;
    void onFire(FireEvent& event);
};
