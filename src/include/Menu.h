/*
    SchumakerLab
    SchumakerTeam
    Hudson Schumaker
*/

#pragma once
#include "../gfx/Scene.h"

class Menu final : public Scene {
private:
	SDL_Texture* titleTexture = nullptr;
	SDL_Rect rectMenu = { 0, 0, 800, 600 };

	short speed = 8;
	const short offset = 400;

	void load() override;
	void input() override;
	void update() override;
	void render() override;
	void unload() override;

public:
	Menu();
	~Menu();

	short run() override;
};