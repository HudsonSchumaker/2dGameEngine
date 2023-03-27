/*
	SchumakerTeam
	Hudson Schumaker
*/

#pragma once
#include "System.h"
#include "Map.h"
#include "Camera.h"

class CameraMovementSystem : public System {
public:
	void update(Map* map, Camera* camera);
};