/*
	Dodoi Lab
	Dodoi Engine
	Hudson Schumaker
*/
#pragma once
#include "Component.h"
#include "../../physics/Vec2.h"
#include "../../physics/Dimension.h"

class BoxCollider final : public Component {
public:
	Dimension bounds;
	Vec2 offset;

	BoxCollider() {}
	BoxCollider(short v) {
		this->bounds.w = v;
		this->bounds.h = v;
	}
	
	BoxCollider(short w, short h) {
		this->bounds.w = w;
		this->bounds.h = h;
	}

	BoxCollider(float x, float y, short w, short h) {
		offset.x = x;
		offset.y = y;
		this->bounds.w = w;
		this->bounds.h = h;
	}

	BoxCollider(Dimension bounds) {
		this->bounds = bounds;
	}

	BoxCollider(Dimension bounds, Vec2 offset) {
		this->bounds = bounds;
		this->offset = offset;
	}

	~BoxCollider() = default;

	BoxCollider clone() {
		return BoxCollider(bounds, offset);
	}
};
