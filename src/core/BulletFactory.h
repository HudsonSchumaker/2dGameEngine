/*
	SchumakerTeam
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
	Entity* createBullet(short id, Vec2 velocity, short damage, bool isFriendly, int duration = 10000);

public:
	static BulletFactory* getInstance();
	Entity* createBullet(BulletType bulletType, bool isFriendly);
};

struct Bullet1 {
	short id = AssetManager::BULLET_1;
	Vec2 velocity = { 0.50f, 0.0f };
	short damage = 5;
	unsigned int duration = 10000;

	Bullet1() {}
};

struct Bullet2 {
	short id = AssetManager::BULLET_1;
	Vec2 velocity = { 100.0f, 0.0f };
	short damage = 5;
	unsigned int duration = 10000;
	
	Bullet2() {}
};

struct Bullet3 {
	short id = AssetManager::BULLET_1;
	Vec2 velocity = { 100.0f, 0.0f };
	short damage = 5;
	unsigned int duration = 10000;
	
	Bullet3() {}
};
