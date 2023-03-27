/*
	SchumakerTeam
	Hudson Schumaker
*/

#pragma once
#include "System.h"
#include "Camera.h"

class RenderSystem final : public System {
private:
	SDL_Renderer* renderer = nullptr;

public:
	RenderSystem();
	~RenderSystem() = default;
	void update(Camera* camera);
};
