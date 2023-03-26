/*
	SchumakerTeam
	Hudson Schumaker
*/

#include "BulletFactory.h"
#include "../gfx/Animation.h"
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

	if (bulletType == BulletType::basic) {
		Bullet1 b1 = {};
		return createBullet(b1.id, b1.velocity, isFriendly, b1.damage);
	}

	if (bulletType == BulletType::plus) {
		Bullet2 b2 = {};
		return createBullet(b2.id, b2.velocity, isFriendly, b2.damage);
	}

	if (bulletType == BulletType::master) {
		Bullet3 b3 = {};
		return createBullet(b3.id, b3.velocity, isFriendly, b3.damage);
	}

	return EntityManager::getInstance()->createEntity();
}

Entity* BulletFactory::createBullet(std::string id, Vec2 velocity, short damage, bool isFriendly, int duration) {
	auto bullet = EntityManager::getInstance()->createEntity();
	bullet->tag = Tag::bullet;

	bullet->addComponent(new Transform(-10.0f));
	bullet->addComponent(new Animation(id, 5, 8, (int)Tag::bullet, true));
	auto animation = bullet->getComponent<Animation>();
	bullet->addComponent(new BoxCollider(animation->bounds.x, animation->bounds.y));
	bullet->addComponent(new RigidBody(velocity));
	bullet->addComponent(new Projectile(isFriendly, damage, duration));

	return bullet;
}