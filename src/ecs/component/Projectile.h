/*
	SchumakerTeam
	Hudson Schumaker
*/

#pragma once
#include "Component.h"

class Projectile final : public Component {
public:
	bool isFriendly = false;
	short damage = 0;
	unsigned int duration = 0;
	unsigned int startTime = 0;

	Projectile() {}
	Projectile(short damage, int duration) {
		this->damage = damage;
		this->duration = duration;
		this->startTime = SDL_GetTicks();
	}

	Projectile(bool isFriendly, short damage, int duration) {
		this->isFriendly = isFriendly;
		this->damage = damage;
		this->duration = duration;
		this->startTime = SDL_GetTicks();
	}

	~Projectile() = default;
};