/*
    SchumakerLab
    SchumakerTeam
    Hudson Schumaker
*/

#pragma once
#include "../gfx/Scene.h"

class Title final : public Scene {
private:
	SDL_Texture* titleTexture = nullptr;
	SDL_Rect rectTitle = { 0, 0, 800, 600 };
	SDL_GameController* controller = nullptr;

	short speed = 8;
	const short offset = 400;

	void load() override;
	void input() override;
	void update() override;
	void render() override;
	void unload() override;

public:
	Title();
	~Title();

	short run() override;
};