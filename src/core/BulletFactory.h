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
	BASIC,
	PLUS,
	MASTER,
	ULTRA,
};

class BulletFactory final {
private:
    inline static BulletFactory* instance;
	Entity* createBullet(Vec2 origin, Vec2 destination, Vec2 velocity, short damage, bool isFriendly, int duration = 10000);

public:
	static BulletFactory* getInstance();
	Entity* createBullet(Vec2 origin, Vec2 destination, BulletType bulletType, bool isFriendly);
};

struct BasicBullet {
	Vec2 velocity = { 24.0f, 24.0f };
	short damage = 4;
	unsigned int duration = 10000;

	BasicBullet() {}
};

struct PlusBullet {
	Vec2 velocity = { 100.0f, 0.0f };
	short damage = 6;
	unsigned int duration = 10000;
	
	PlusBullet() {}
};

struct MasterBullet {
	Vec2 velocity = { 100.0f, 0.0f };
	short damage = 8;
	unsigned int duration = 10000;
	
	MasterBullet() {}
};

struct UltraBullet {
	Vec2 velocity = { 100.0f, 0.0f };
	short damage = 8;
	unsigned int duration = 10000;
	
	UltraBullet() {}
};
