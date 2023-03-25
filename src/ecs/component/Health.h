/*
	Windows 10 - 11
	SchumakerTeam
	Hudson Schumaker
*/

#pragma once
#include "Component.h"

class Health final : public Component {
public:
	int life = 0;

	Health() {}
	Health(int life) {
		this->life = life;
	}

	~Health() = default;

	Health clone() {
		return Health(life);
	}
};
