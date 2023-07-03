/*
	Dodoi Lab
	Dodoi Engine
	Hudson Schumaker
*/

#pragma once
#include "System.h"
#include "../../core/Camera.h"

class RenderTextSystem final : public System {
private:
	SDL_Renderer* renderer = nullptr;
	void renderTextLabel(Camera* camera);
	void renderSpriteText(Camera* camera);

public:
	RenderTextSystem();
	~RenderTextSystem() = default;
	void update(Camera* camera);
};
