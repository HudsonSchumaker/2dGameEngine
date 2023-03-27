/*
	SchumakerTeam
	Hudson Schumaker
*/

#include "../include/DamageSystem.h"
#include "../include/EventBus.h"
#include "../include/EntityManager.h"

DamageSystem::DamageSystem() {
	subscribeToEvents();
}

void DamageSystem::subscribeToEvents() {
	EventBus::getInstance()->subscribeToEvent<CollisionEvent>(this, &DamageSystem::onCollision);
}

void DamageSystem::onCollision(CollisionEvent& event) {

	if (event.a->tag == Tag::bullet) {
		EntityManager::getInstance()->killEntity(event.a);
		if (event.b->tag == Tag::enemy) {
			EntityManager::getInstance()->killEntity(event.b);
		}
		return;
	}

	std::cout << "entities: " <<
		EntityManager::getInstance()->getEntities().size() 
	<< std::endl;

	std::cout << "a: " << event.a->id << std::endl;
	std::cout << "b:" << event.b->id << std::endl;
}
