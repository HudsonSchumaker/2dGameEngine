/*
	SchumakerTeam
	Hudson Schumaker
*/

#include "RenderColliderSystem.h"
#include "../../gfx/Gfx.h"
#include "../../gfx/Color.h"
#include "../EntityManager.h"
#include "../../gfx/Sprite.h"
#include "../component/Radar.h"
#include "../component/Transform.h"
#include "../component/BoxCollider.h"

RenderColliderSystem::RenderColliderSystem() {
	this->renderer = Gfx::getInstance()->getRenderer();
}

void RenderColliderSystem::update(Camera* camera) {
	renderBoxCollider(camera);
	renderRadarCollider();
}

void RenderColliderSystem::renderBoxCollider(Camera* camera) {
	auto entities = EntityManager::getInstance()->getEntitiesWithComponent<BoxCollider>();

	for (auto& entity : entities) {
		Transform* transform = entity->getComponent<Transform>();
		BoxCollider* collider = entity->getComponent<BoxCollider>();

		if (collider && transform) {
			SDL_FRect colliderRect = {
					transform->position.x + collider->offset.x - camera->x, 
					transform->position.y + collider->offset.y - camera->y,
					(float)collider->bounds.w,
					(float)collider->bounds.h
			};
			
			SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
			SDL_RenderDrawRectF(renderer, &colliderRect);
		}
	}
}

void RenderColliderSystem::renderRadarCollider() {
	auto entities = EntityManager::getInstance()->getEntitiesWithComponent<Radar>();

	for (auto& entity : entities) {
		Transform* transform = entity->getComponent<Transform>();
		Radar* radar = entity->getComponent<Radar>();

		if (radar && transform) {
			Gfx::getInstance()->drawDashedCircle(
				transform->position.x + radar->offset.x,
				transform->position.y + radar->offset.y,
			  	radar->r, 
				8,
				Color::getRed());
		}
	}
}
