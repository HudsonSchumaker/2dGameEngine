/*
	SchumakerTeam
	Hudson Schumaker
*/

#pragma once
#include "../gfx/Scene.h"

class Splash final : public Scene {
private:
	SDL_Texture* logoTexture = nullptr;
	SDL_Rect rect = { 0, 0, 0, 0 };

	void load() override;
	void input() override;
	void update() override;
	void render() override;
	void unload() override;

public:
	Splash();
	~Splash();

	short run() override;
};