/*
	Dodoi Lab
	Dodoi Engine
	Hudson Schumaker
*/

#pragma once
#include "System.h"
#include "../../core/Camera.h"

class PrimitiveRenderSystem final : public System {
private:
	SDL_Renderer* renderer = nullptr;

    void renderBox(Camera* camera);
    void renderCircle(Camera* camera);

public:
	PrimitiveRenderSystem();
	~PrimitiveRenderSystem() = default;
	void update(Camera* camera);
};
