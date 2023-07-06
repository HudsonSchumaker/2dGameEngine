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

Entity* BulletFactory::createBullet(BulletType bulletType, bool isFriendly) {
	if (bulletType == BulletType::BASIC) {
		BasicBullet b1 = {};
		return createBullet(b1.velocity, isFriendly, b1.damage);
	}

	if (bulletType == BulletType::PLUS) {
		PlusBullet b2 = {};
		return createBullet(b2.velocity, isFriendly, b2.damage);
	}

	if (bulletType == BulletType::MASTER) {
		MasterBullet b3 = {};
		return createBullet(b3.velocity, isFriendly, b3.damage);
	}

	if (bulletType == BulletType::ULTRA) {
		UltraBullet b3 = {};
		return createBullet(b3.velocity, isFriendly, b3.damage);
	}

	return EntityManager::getInstance()->createEntity();
}

Entity* BulletFactory::createBullet(Vec2 velocity, short damage, bool isFriendly, int duration) {
	auto bullet = EntityManager::getInstance()->createEntity();
	bullet->tag = Tag::bullet;

	bullet->addComponent(new Transform(-10.0f));

	bullet->addComponent(new BoxCollider(animation->getSize().w, animation->getSize().h));
	bullet->addComponent(new RigidBody(velocity));
	bullet->addComponent(new Projectile(isFriendly, damage, duration));

	return bullet;
}