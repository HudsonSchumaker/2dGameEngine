/*
	Dodoi Lab
	Dodoi Engine
	Hudson Schumaker
*/

#include "DamageSystem.h"
#include "../EntityManager.h"
#include "../component/Health.h"
#include "../../event/EventBus.h"

DamageSystem::DamageSystem() {
	subscribeToEvents();
}

void DamageSystem::subscribeToEvents() {
	EventBus::getInstance()->subscribeToEvent<CollisionEvent>(this, &DamageSystem::onCollision);
}

void DamageSystem::onCollision(CollisionEvent& event) {

	/* if (event.a->tag == Tag::bullet) {
		EntityManager::getInstance()->killEntity(event.a);
		if (event.b->tag == Tag::enemy) {
			EntityManager::getInstance()->killEntity(event.b);
		}
	} */

	if (event.b->tag == Tag::enemy && event.a->tag == Tag::ui) {
		Health* health = event.b->getComponent<Health>();
		if (health) {
			health->healthPercentage -= 1;
		}
	}
}
