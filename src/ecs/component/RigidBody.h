/*
	Dodoi Lab
	Dodoi Engine
	Hudson Schumaker
*/

#pragma once
#include "Component.h"
#include "../../physics/Vec2.h"

class RigidBody final : public Component {
public:
    Vec2 velocity;

    RigidBody() {}
    RigidBody(float x, float y) {
        this->velocity.x = x;
        this->velocity.y = y;
    }

    RigidBody(Vec2 velocity) {
        this->velocity = velocity;
    }

    ~RigidBody() = default;

    RigidBody clone() {
        return RigidBody(velocity.x, velocity.y);
    }
};
