/*
	Windows 10 - 11
	SchumakerTeam
	Hudson Schumaker
*/

#pragma once
#include "System.h"

class RenderColliderSystem final : public System {
private:
	SDL_Renderer* renderer = nullptr;

public:
	RenderColliderSystem();
	~RenderColliderSystem() = default;
	void update(float dt) override;
};

