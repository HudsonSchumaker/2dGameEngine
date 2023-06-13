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
        std::vector<Entity*> list;
        for (auto& e : entities) {
            if (e->getComponent<T>()) {
                list.push_back(e);
            }
        }
        return list; 
    }

    std::vector<Entity*> getEntitiesWithTag(Tag tag);
    void update();
    void killEntity(Entity* entity);
    void clear();
};
