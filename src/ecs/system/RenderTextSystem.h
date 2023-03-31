/*
	SchumakerTeam
	Hudson Schumaker
*/

#pragma once
#include "System.h"
#include "../../core/Camera.h"

class RenderTextSystem final : public System {
private:
	SDL_Renderer* renderer = nullptr;

public:
	RenderTextSystem();
	~RenderTextSystem() = default;
	void update(Camera* camera);
};
