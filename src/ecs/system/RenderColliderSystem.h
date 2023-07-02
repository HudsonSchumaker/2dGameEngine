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
	void renderBoxCollider(Camera* camera);
	void renderRadarCollider();

public:
	RenderColliderSystem();
	~RenderColliderSystem() = default;
	void update(Camera* camera);
};
