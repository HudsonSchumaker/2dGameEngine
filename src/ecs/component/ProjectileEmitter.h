/*
	SchumakerTeam
	Hudson Schumaker
*/

#pragma once
#include "Component.h"
#include "../../physics/Vec2.h"
#include "../../core/BulletFactory.h"

class ProjectileEmiter final : public Component {
public:
	bool isFriendly = false;
	int repeatFrequency = 0;
	unsigned int lastEmissionTime = 0;
	BulletType bulletType = BulletType::basic;

	ProjectileEmiter(bool isFriendly, BulletType bulletType, int repeatFrequency = 0) {
		this->isFriendly = isFriendly;
		this->repeatFrequency = repeatFrequency;
		this->bulletType = bulletType;
		this->lastEmissionTime = SDL_GetTicks();
	}
};