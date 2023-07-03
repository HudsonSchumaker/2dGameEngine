/*
	Dodoi Lab
	Dodoi Engine
	Hudson Schumaker
*/

#pragma once
#include "System.h"
#include "../../core/Map.h"
#include "../../core/Camera.h"

class CameraMovementSystem : public System {
public:
	void update(Map* map, Camera* camera);
};
