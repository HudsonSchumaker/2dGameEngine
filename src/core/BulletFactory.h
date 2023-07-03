/*
	SchumakerTeam
	Dodoi Engine
	Hudson Schumaker
*/

#pragma once
#include "../ecs/Entity.h"
#include "../physics/Vec2.h"
#include "../gfx/AssetManager.h"

enum class BulletType {
	basic,
	plus,
	master,
};

class BulletFactory final {
private:
    inline static BulletFactory* instance;
	Entity* createBullet(std::string id, Vec2 velocity, short damage, bool isFriendly, int duration = 10000);

public:
	static BulletFactory* getInstance();
	Entity* createBullet(BulletType bulletType, bool isFriendly);
};

//TODO: fix bullet id and types

struct Bullet1 {
	std::string id = "1";
	Vec2 velocity = { 0.50f, 0.0f };
	short damage = 4;
	unsigned int duration = 10000;

	Bullet1() {}
};

struct Bullet2 {
	std::string id = "1";
	Vec2 velocity = { 100.0f, 0.0f };
	short damage = 6;
	unsigned int duration = 10000;
	
	Bullet2() {}
};

struct Bullet3 {
	std::string id = "1";
	Vec2 velocity = { 100.0f, 0.0f };
	short damage = 8;
	unsigned int duration = 10000;
	
	Bullet3() {}
};
