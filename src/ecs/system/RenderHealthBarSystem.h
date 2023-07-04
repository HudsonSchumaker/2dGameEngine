/*
	Dodoi Lab
	Dodoi Engine
	Hudson Schumaker
*/

#pragma once
#include "System.h"
#include "../EntityManager.h"
#include "../../core/Camera.h"

class RenderHealthBarSystem final : public System {
private:
	SDL_Renderer* renderer = nullptr;
	float getWidth(Entity* entity);

public:
	RenderHealthBarSystem();
	~RenderHealthBarSystem() = default;
    void update(Camera* camera);
};
