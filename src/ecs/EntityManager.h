/*
	Dodoi Lab
	Dodoi Engine
	Hudson Schumaker
*/

#pragma once
#include "Entity.h"
#include "../include/Common.h"

class EntityManager final {
private:
    unsigned long index = 0;
    inline static EntityManager* instance;
    std::vector<Entity*> entities;
    std::set<Entity*> entitiesToBeKilled;
    std::unordered_map<std::type_index, std::vector<Entity*>> entitiesByComponent;

    EntityManager();
    ~EntityManager();

public:
    static EntityManager* getInstance();
    Entity* createEntity();
    Entity* createEntity(float x, float y);
    Entity* getEntity(unsigned long id);
    const std::vector<Entity*>& getEntities() const;
    void removeEntity(Entity* entity);
    
    template<typename T>
    std::vector<Entity*> getEntitiesWithComponent() {
        /* std::vector<Entity*> list;
        for (auto& e : entities) {
            if (e->getComponent<T>()) {
                list.push_back(e);
            }
        }
        return list;  */
        auto it = entitiesByComponent.find(std::type_index(typeid(T)));
        if (it == entitiesByComponent.end()) {
            return std::vector<Entity*>();
        } else {
            return it->second;
        }
    }

    template<typename T>
	void addEntityComponent(Entity* entity, T* component) {
		auto it = entitiesByComponent.find(std::type_index(typeid(T)));
        if (it == entitiesByComponent.end()) {
            std::vector<Entity*> list;
            list.push_back(entity);
            entitiesByComponent[typeid(T)] = list;
        } else {
            it->second.push_back(entity);
        }
	}

    template<typename T>
	std::vector<Entity*> getComponentEntities() {
		auto it = entitiesByComponent.find(std::type_index(typeid(T)));
        if (it == entitiesByComponent.end()) {
            return std::vector<Entity*>();
        } else {
            return it->second;
        }
	}

    void update();
    std::vector<Entity*> getEntitiesWithTag(Tag tag);
    void killEntity(Entity* entity);
    void clear();
};
