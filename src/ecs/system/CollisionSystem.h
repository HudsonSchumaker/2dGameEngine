/*
	Windows 10 - 11
	SchumakerTeam
	Hudson Schumaker
*/

#pragma once
#include "System.h"
#include "../component/Transform.h"
#include "../component/BoxCollider.h"

class CollisionSystem final : public System {
private:
	bool checkAABBCollision(Transform* tA, Transform* tB, BoxCollider* bA, BoxCollider* bB);

public:
	CollisionSystem() = default;
	~CollisionSystem() = default;
	void update(float dt) override;
};
