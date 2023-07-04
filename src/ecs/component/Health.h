/*
	Dodoi Lab
	Dodoi Engine
	Hudson Schumaker
*/

#pragma once
#include "Component.h"

class Health final : public Component {
public:
	int healthPercentage = 0;

	Health() {}
	Health(int healthPercentage) {
		this->healthPercentage = healthPercentage;
	}

	~Health() = default;

	Health clone() {
		return Health(healthPercentage);
	}
};
