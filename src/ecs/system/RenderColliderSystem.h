/*
	SchumakerTeam
	Hudson Schumaker
*/

#pragma once
#include "System.h"
#include "../../core/Camera.h"

class RenderColliderSystem final : public System {
private:
	SDL_Renderer* renderer = nullptr;

public:
	RenderColliderSystem();
	~RenderColliderSystem() = default;
	void update(Camera* camera);
};
