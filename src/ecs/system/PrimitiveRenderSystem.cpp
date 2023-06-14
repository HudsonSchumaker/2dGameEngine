/*
	Dodoi Lab
	Dodoi Engine
	Hudson Schumaker
*/

#include "PrimitiveRenderSystem.h"
#include "../../gfx/Box.h"
#include "../../gfx/Gfx.h"
#include "../EntityManager.h"
#include "../component/Transform.h"

PrimitiveRenderSystem::PrimitiveRenderSystem() {
	this->renderer = Gfx::getInstance()->getRenderer();
}

void PrimitiveRenderSystem::update(Camera* camera) {
	renderBox(camera);
    renderCircle(camera);
}

void PrimitiveRenderSystem::renderBox(Camera* camera) {
    auto entities = EntityManager::getInstance()->getEntitiesWithComponent<Box>();
	sort(entities.begin(), entities.end(), Box::compareAsc);

	for (auto& entity : entities) {
		Box* box = entity->getComponent<Box>();
		Transform* transform = entity->getComponent<Transform>();
		
		if (box && transform) {
			bool isOutsideCameraView = (
				transform->position.x + (transform->scale.x * box->w) < camera->x ||
				transform->position.x > camera->x + camera->w ||
				transform->position.y + (transform->scale.y * box->h) < camera->y ||
				transform->position.y > camera->y + camera->h
			);

			if (isOutsideCameraView && !box->isFixed) {
                continue;
            }

			SDL_Rect dstRect = {
				transform->position.x - (box->isFixed ? 0 : camera->x), 
				transform->position.y - (box->isFixed ? 0 : camera->y),
				box->w * transform->scale.x,
				box->h * transform->scale.y
			};

            Gfx::getInstance()->drawBox(dstRect, box->color);
		}
	}
}

void PrimitiveRenderSystem::renderCircle(Camera* camera) {

}