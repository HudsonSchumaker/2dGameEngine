/*
	Dodoi Lab
	Dodoi Engine
	Hudson Schumaker
*/

#pragma once
#include "System.h"
#include "../EntityManager.h"
#include "../component/Transform.h"

class RadarSystem final : public System {
public: 
    void update();
};
