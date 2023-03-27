/*
	SchumakerTeam
	Hudson Schumaker
*/

#pragma once
#include "System.h"
#include "Camera.h"

class AnimationSystem final : public System {
private:
	SDL_Renderer* renderer = nullptr;

public:
	AnimationSystem();
	~AnimationSystem() = default;
	void update(Camera* camera);
};