/*
	Windows 10 - 11
	SchumakerTeam
	Hudson Schumaker
*/

#pragma once
#include "../ecs/Entity.h"
#include "../ecs/component/Component.h"

class Sprite final : public Component {
public:
	float w = 0.0f, h = 0.0f;
	bool flip = false;
	bool isFixed = false;
	SDL_Texture* texture = nullptr;
	SDL_Rect srcRect;
	short layer = 10;

	Sprite(short id);
	Sprite(short id, bool isFixed);
	Sprite(short id, short layer);
	Sprite(short id, bool isFixed, short layer);
	Sprite(short id, int srcX, int srcY, int w, int h, short layer);
	Sprite(short id, int srcX, int srcY, int w, int h, bool isFixed, short layer);
	~Sprite();

	static bool compareAsc(Entity* e1, Entity* e2);
	static bool compareDesc(Entity* e1, Entity* e2);
};