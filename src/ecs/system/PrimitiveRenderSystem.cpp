/*
	Dodoi Lab
	Dodoi Engine
	Hudson Schumaker
*/

#include "PrimitiveRenderSystem.h"
#include "../../gfx/Box.h"
#include "../../gfx/Gfx.h"
#include "../../gfx/Circle.h"
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
				static_cast<int>(transform->position.x - (box->isFixed ? 0 : camera->x)), 
				static_cast<int>(transform->position.y - (box->isFixed ? 0 : camera->y)),
				static_cast<int>(box->w * transform->scale.x),
				static_cast<int>(box->h * transform->scale.y)
			};

            Gfx::getInstance()->drawBox(dstRect, box->color);
		}
	}
}

void PrimitiveRenderSystem::renderCircle(Camera* camera) {
	auto entities = EntityManager::getInstance()->getEntitiesWithComponent<Circle>();
	sort(entities.begin(), entities.end(), Circle::compareAsc);

	for (auto& entity : entities) {
		Circle* circle = entity->getComponent<Circle>();
		Transform* transform = entity->getComponent<Transform>();
		
		if (circle && transform) {
			auto wh =  circle->getSize().w;
			bool isOutsideCameraView = (
				transform->position.x + (transform->scale.x * wh) < camera->x ||
				transform->position.x > camera->x + camera->w ||
				transform->position.y + (transform->scale.y * wh) < camera->y ||
				transform->position.y > camera->y + camera->h
			);

			if (isOutsideCameraView && !circle->isFixed) {
                continue;
            }

			auto x = static_cast<int>(transform->position.x - (circle->isFixed ? 0 : camera->x)); 
			auto y = static_cast<int>(transform->position.y - (circle->isFixed ? 0 : camera->y));
			auto r = static_cast<int>(wh * transform->scale.x);
	
            //Gfx::getInstance()->drawCircle(x, y, r, circle->color);
			Gfx::getInstance()->drawDashedCircle(x, y, r, 8, circle->color);
		}
	}
}
