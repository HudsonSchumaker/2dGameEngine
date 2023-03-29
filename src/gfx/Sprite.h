/*
	SchumakerTeam
	Hudson Schumaker
*/

#pragma once
#include "../ecs/Entity.h"
#include "../ecs/component/Component.h"

class Sprite final : public Component {
public:
	float w = 0.0f;
	float h = 0.0f;
	SDL_Rect srcRect;
	short layer = 10;
	bool flip = false;
	bool isFixed = false;
	SDL_Texture* texture = nullptr;

	Sprite(const std::string& name);
	Sprite(const std::string& name, bool isFixed);
	Sprite(const std::string& name, short layer);
	Sprite(const std::string& name, bool isFixed, short layer);
	Sprite(const std::string& name, int srcX, int srcY, int w, int h, short layer);
	Sprite(const std::string& name, int srcX, int srcY, int w, int h, bool isFixed, short layer);

	void setOnCenter();
	void setOnCenterX();
	void setOnCenterY();
	~Sprite();

	static bool compareAsc(Entity* e1, Entity* e2);
	static bool compareDesc(Entity* e1, Entity* e2);
};
