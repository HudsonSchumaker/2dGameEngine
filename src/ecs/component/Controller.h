/*
	SchumakerTeam
	Hudson Schumaker
*/

#pragma once
#include "Component.h"
#include "../../physics/Vec2.h"

class Controller final : public Component {
public:
	Vec2 velocity;

	Controller() {}
	Controller(float x, float y) {
		this->velocity.x = x;
		this->velocity.y = y;
	}

	Controller(Vec2 velocity) {
		this->velocity = velocity;
	}

	~Controller() = default;

	Controller clone() {
		return Controller(velocity);
	}
};