/*
	SchumakerTeam
	Hudson Schumaker
*/

#include "MouseSystem.h"
#include "../EntityManager.h"
#include "../component/Button.h"
#include "../../event/EventBus.h"
#include "../component/Transform.h"
#include "../component/BoxCollider.h"

void MouseSystem::update(MousePointer pointer) {
    auto entities = EntityManager::getInstance()->getEntitiesWithComponent<Button>();

	for (auto& entity : entities) {
		Transform* transform = entity->getComponent<Transform>();
        BoxCollider* collider = entity->getComponent<BoxCollider>();

        if (collider && transform) {
            SDL_Rect box = { 
                static_cast<int>(transform->position.x), 
                static_cast<int>(transform->position.y),
                collider->bounds.w, 
                collider->bounds.h 
            };

            if (isInside(pointer.getBounds(), box)) {
                EventBus::getInstance()->emitEvent<MouseHoverEvent>(entity, true);
            } else {
                EventBus::getInstance()->emitEvent<MouseHoverEvent>(entity, false);
            }
        }
    }
}

bool MouseSystem::isInside(const SDL_Rect& box1, const SDL_Rect& box2) const {
    SDL_Rect aabb1 = { box1.x - box1.w / 2, box1.y - box1.h / 2, box1.w, box1.h };
    SDL_Rect aabb2 = { box2.x - box2.w / 2, box2.y - box2.h / 2, box2.w, box2.h };

    // Check if aabb1 is inside aabb2
    if (aabb1.x >= aabb2.x && aabb1.y >= aabb2.y
        && aabb1.x + aabb1.w <= aabb2.x + aabb2.w
        && aabb1.y + aabb1.h <= aabb2.y + aabb2.h) {
        
        return true;
    }

    return false;
}
