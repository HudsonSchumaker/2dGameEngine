/*
	SchumakerTeam
	Hudson Schumaker
*/

#include "../include/MovementSystem.h"
#include "../include/EntityManager.h"
#include "../include/Transform.h"
#include "../include/RigidBody.h"

void MovementSystem::update(float dt) {
	auto entities = EntityManager::getInstance()->getEntitiesWithComponent<RigidBody>();

	for (auto& entity : entities) {
		RigidBody* rigidBody = entity->getComponent<RigidBody>();
		Transform* transform = entity->getComponent<Transform>();

		if (rigidBody && transform) {
			transform->position.x += rigidBody->velocity.x * dt;
			transform->position.y += rigidBody->velocity.y * dt;
		}
	}
}
