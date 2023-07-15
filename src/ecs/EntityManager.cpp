/*
	Dodoi Lab
	Dodoi Engine
	Hudson Schumaker
*/

#include "EntityManager.h"
#include "../physics/Vec2.h"
#include "../event/EventBus.h"
#include "../ecs/component/Transform.h"
#include "../event/AddEntityComponentEvent.h"

EntityManager::EntityManager() {
	//EventBus::getInstance()->subscribeToEvent<AddEntityComponentEvent>(this, &EntityManager::addEntityComponent);
}

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
	entity->id = ++index;
	auto component = entity->addComponent(new Transform(Vec2(x, y)));
	entities.push_back(entity);
	addEntityComponent(entity, component);
	return entity;
}

Entity* EntityManager::getEntity(unsigned long id) {
	for (auto& e : entities) {
		if (e->id == id) {
			return e;
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

 	std::vector<std::thread> threads;
    for (auto& it : entitiesByComponent) {
        auto iterator = std::find(it.second.begin(), it.second.end(), entity);
        if (iterator != it.second.end()) {
            threads.push_back(std::thread([&it, iterator, this]() {
                entitiesByComponent[it.first].erase(iterator);
            }));
        }
    }

    for (auto& thread : threads) {
        thread.join();
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
