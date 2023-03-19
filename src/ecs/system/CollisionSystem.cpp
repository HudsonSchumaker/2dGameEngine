/*
	Windows 10 - 11
	SchumakerTeam
	Hudson Schumaker
*/

#include "CollisionSystem.h"
#include "../EntityManager.h"
#include "../../event/EventBus.h"
#include "../../event/CollisionEvent.h"

void CollisionSystem::update(float dt) {
	auto entities = EntityManager::getInstance()->getEntitiesWithComponent<BoxCollider>();
    for (int i = 0; i < entities.size(); i++) {
        Entity* a = entities[i];
        auto aTransform = a->getComponent<Transform>();
        auto aCollider = a->getComponent<BoxCollider>();

        for (auto j = i; j < entities.size(); j++) {
            Entity* b = entities[j];

            if (a->id == b->id) {
                continue;
            }

            auto bTransform = b->getComponent<Transform>();
            auto bCollider = b->getComponent<BoxCollider>();

            if (checkAABBCollision(aTransform, bTransform, aCollider, bCollider)) {
                EventBus::getInstance()->emitEvent<CollisionEvent>(a, b);
            }
        }
    }
}

bool CollisionSystem::checkAABBCollision(Transform* tA, Transform* tB, BoxCollider* bA, BoxCollider* bB) {
    float aX = tA->position.x + bA->offset.x;
    float aY = tA->position.y + bA->offset.y;
    float aW = bA->bounds.w;
    float aH = bA->bounds.h;

    float bX = tB->position.x + bB->offset.x;
    float bY = tB->position.y + bB->offset.y;
    float bW = bB->bounds.w;
    float bH = bB->bounds.h;
    
    return (
        aX < bX + bW &&
        aX + aW > bX &&
        aY < bY + bH &&
        aY + aH > bY
    );
}