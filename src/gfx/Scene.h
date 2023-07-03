/*
	Dodoi Lab
	Dodoi Engine
	Hudson Schumaker
*/

#pragma once
#include "Gfx.h"
#include "../core/Camera.h"
#include "../include/Common.h"

class Scene {
private:
	virtual void load() = 0;
	virtual void input() = 0;
	virtual void update() = 0;
	virtual void render() = 0;
	virtual void unload() = 0;

protected:
	Camera camera;
	SDL_Renderer* renderer;
	int millisecsPreviousFrame = 0;
	float deltaTime = 0.0f;

	bool isRunning = false;
	short exit = 0;

	float calculateDeltaTime();
	void beginRender();
	void endRender();

public:
	Scene();
	virtual ~Scene() = default;
	virtual short run() = 0;
};
