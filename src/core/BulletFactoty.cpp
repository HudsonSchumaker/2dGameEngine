/*
	SchumakerTeam
	Dodoi Engine
	Hudson Schumaker
*/

#include "BulletFactory.h"
#include "../gfx/Bullet.h"
#include "../ecs/EntityManager.h"
#include "../ecs/component/RigidBody.h"
#include "../ecs/component/Transform.h"
#include "../ecs/component/Projectile.h"
#include "../ecs/component/BoxCollider.h"

BulletFactory* BulletFactory::getInstance() {
	if (instance == nullptr) {
		instance = new BulletFactory();
	}

	return instance;
}

Entity* BulletFactory::createBullet(const Vec2 origin, const Vec2 destination, BulletType bulletType, bool isFriendly) {
	if (bulletType == BulletType::BASIC) {
		BasicBullet b1 = {};
		return createBullet(origin, destination, b1.velocity, isFriendly, b1.damage);
	}

	if (bulletType == BulletType::PLUS) {
		PlusBullet b2 = {};
		return createBullet(origin, destination, b2.velocity, isFriendly, b2.damage);
	}

	if (bulletType == BulletType::MASTER) {
		MasterBullet b3 = {};
		return createBullet(origin, destination, b3.velocity, isFriendly, b3.damage);
	}

	if (bulletType == BulletType::ULTRA) {
		UltraBullet b4 = {};
		return createBullet(origin, destination, b4.velocity, isFriendly, b4.damage);
	}

	return nullptr;
}

Entity* BulletFactory::createBullet(const Vec2 origin, const Vec2 destination, Vec2 velocity, short damage, bool isFriendly, int duration) {
	auto bullet = EntityManager::getInstance()->createEntity(origin.x, origin.y);
	bullet->tag = Tag::bullet;
 
	bullet->addComponent(new Bullet(bullet->id, destination));
	auto bulletDimension = bullet->getComponent<Bullet>()->getDimension();

	bullet->addComponent(new BoxCollider(bulletDimension));
	bullet->addComponent(new RigidBody(velocity));
	bullet->addComponent(new Projectile(isFriendly, damage, duration));

	return bullet;
}