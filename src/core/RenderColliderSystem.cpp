/*
	SchumakerTeam
	Hudson Schumaker
*/

#include "../include/RenderColliderSystem.h"
#include "../include/Gfx.h"
#include "../include/EntityManager.h"
#include "../include/Sprite.h"
#include "../include/Transform.h"
#include "../include/BoxCollider.h"

RenderColliderSystem::RenderColliderSystem() {
	this->renderer = Gfx::getInstance()->getRenderer();
}

void RenderColliderSystem::update(Camera* camera) {
	auto entities = EntityManager::getInstance()->getEntitiesWithComponent<BoxCollider>();

	for (auto& entity : entities) {
		Transform* transform = entity->getComponent<Transform>();
		BoxCollider* collider = entity->getComponent<BoxCollider>();

		if (collider && transform) {
			SDL_FRect colliderRect = {
					transform->position.x + collider->offset.x - camera->x, 
					transform->position.y + collider->offset.y -camera->y,
					(float)collider->bounds.w,
					(float)collider->bounds.h
			};
			SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
			SDL_RenderDrawRectF(renderer, &colliderRect);
		}
	}
};
