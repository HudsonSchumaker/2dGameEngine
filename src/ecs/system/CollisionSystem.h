/*
	Dodoi Lab
	Dodoi Engine
	Hudson Schumaker
*/

#pragma once
#include "System.h"
#include "../component/Transform.h"
#include "../component/BoxCollider.h"

class CollisionSystem final : public System {
private:
	bool checkAABBCollision(Transform* tA, Transform* tB, BoxCollider* bA, BoxCollider* bB) const;

public:
	CollisionSystem() = default;
	~CollisionSystem() = default;
	void update();
};
