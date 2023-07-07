/*
	Dodoi Lab
	Dodoi Engine
	Hudson Schumaker
*/

#include "MovementSystem.h"
#include "../EntityManager.h"
#include "../component/Waypoint.h"
#include "../component/Transform.h"
#include "../component/RigidBody.h"
#include "../component/Projectile.h"
#include "../../gfx/Bullet.h"

void MovementSystem::update(float dt) {
	auto entities = EntityManager::getInstance()->getEntitiesWithComponent<RigidBody>();

	for (auto& entity : entities) {
		if (entity->getComponent<Waypoint>()) {
			continue;
		}

		RigidBody* rigidBody = entity->getComponent<RigidBody>();
		Transform* transform = entity->getComponent<Transform>();

		if (rigidBody && transform) {
			Bullet* bullet = entity->getComponent<Bullet>();
			if (bullet) {
				bullet->originX += bullet->directionX * rigidBody->velocity.x * dt;
				bullet->originY += bullet->directionY * rigidBody->velocity.y * dt;
				
				continue;
			}

			transform->position.x += rigidBody->velocity.x * dt;
			transform->position.y += rigidBody->velocity.y * dt;
		}
	}
}
