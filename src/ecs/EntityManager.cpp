/*
	Dodoi Lab
	Dodoi Engine
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
	return createEntity(0.0f, 0.0f);
}

Entity* EntityManager::createEntity(float x, float y) {
	Entity* entity = new Entity();
	index++;
	entity->id = index;
	entity->addComponent(new Transform(Vec2(x, y)));
	entities.push_back(entity);
	return entity;
}

Entity* EntityManager::getEntity(unsigned long id) {
	// sort entities
	sort(entities.begin(), entities.end(), compareAsc);
	
	unsigned long low = 0;
  	unsigned long high = entities.size() - 1;

	// search using binray search
	while (low <= high) {
    	unsigned long mid = (low + high) / 2;

    	if (entities[mid]->id == id) {
    		return entities[mid];
    	} else if (entities[mid]->id < id) {
    		low = mid + 1;
    	} else {
    		high = mid - 1;
    	}
	}

    return nullptr;
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

bool EntityManager::compareAsc(const Entity* e1, const Entity* e2) {
	return (e1->id < e2->id);
}

void EntityManager::clear() {
	for (auto& e : entities) {
		removeEntity(e);
	}
	index = 0;
}
