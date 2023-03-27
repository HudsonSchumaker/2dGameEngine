/*
    SchumakerTeam
    Hudson Schumaker
*/

#pragma once
#include "System.h"
#include "FireEvent.h"

class ProjectileEmitSystem final : public System {
private:
    void subscribeToEvents();

public:
    ProjectileEmitSystem();
    ~ProjectileEmitSystem() = default;
    void onFire(FireEvent& event);
};
