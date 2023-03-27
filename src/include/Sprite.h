/*
	SchumakerTeam
	Hudson Schumaker
*/

#pragma once
#include "Entity.h"
#include "Component.h"

class Sprite final : public Component {
public:
	float w = 0.0f, h = 0.0f;
	bool flip = false;
	bool isFixed = false;
	SDL_Texture* texture = nullptr;
	SDL_Rect srcRect;
	short layer = 10;

	Sprite(const std::string& name);
	Sprite(const std::string& name, bool isFixed);
	Sprite(const std::string& name, short layer);
	Sprite(const std::string& name, bool isFixed, short layer);
	Sprite(const std::string& name, int srcX, int srcY, int w, int h, short layer);
	Sprite(const std::string& name, int srcX, int srcY, int w, int h, bool isFixed, short layer);
	~Sprite();

	static bool compareAsc(Entity* e1, Entity* e2);
	static bool compareDesc(Entity* e1, Entity* e2);
};