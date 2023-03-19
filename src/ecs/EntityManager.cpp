/*
	Windows 10 - 11
	SchumakerTeam
	Hudson Schumaker
*/

#include "EntityManager.h"
#include "../physics/Vec2.h"
#include "../ecs/component/Transform.h"

EntityManager::EntityManager() {}
EntityManager::~EntityManager() {
	clear();
}

EntityManager* EntityManager::getInstance() {
	if (instance == nullptr) {
		instance = new EntityManager();
	}

	return instance;
}

Entity* EntityManager::createEntity() {
	Entity* entity = new Entity();
	entity->id = index;
	index++;
	entities.push_back(entity);
	return entity;
}

Entity* EntityManager::createEntity(float x, float y) {
	Entity* entity = new Entity();
	entity->id = index;
	index++;
	entity->addComponent(new Transform(Vec2(x, y)));
	entities.push_back(entity);
	return entity;
}

void EntityManager::removeEntity(Entity* entity) {
	auto it = std::find(entities.begin(), entities.end(), entity);
	if (it != entities.end()) {
		entities.erase(it);
		delete entity;
	}
}

void EntityManager::update() {
	for (auto& e : entitiesToBeKilled) {
		removeEntity(e);
	}

	entitiesToBeKilled.clear();
}

void EntityManager::killEntity(Entity* entity) {
	entitiesToBeKilled.insert(entity);
}

const std::vector<Entity*>& EntityManager::getEntities() const {
	return entities;
}

std::vector<Entity*> EntityManager::getEntitiesWithTag(Tag tag) {
	std::vector<Entity*> list;
	for (auto& e : entities) {
		if (e->tag == tag) {
			list.push_back(e);
		}
	}
	return list;
}

void EntityManager::clear() {
	for (auto& e : entities) {
		removeEntity(e);
	}
	index = 0;
}
