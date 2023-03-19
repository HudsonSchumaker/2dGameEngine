/*
    Windows 10 - 11
    SchumakerTeam
    Hudson Schumaker
*/

#pragma once
#include "System.h"
#include "../../event/CollisionEvent.h"

class DamageSystem final : public System {
private:
    void subscribeToEvents();

public:
    DamageSystem();
    ~DamageSystem() = default;

    void onCollision(CollisionEvent& event);
    void update(float dt) override;
};

