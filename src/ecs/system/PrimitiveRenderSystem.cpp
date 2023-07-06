/*
	Dodoi Lab
	Dodoi Engine
	Hudson Schumaker
*/

#include "PrimitiveRenderSystem.h"
#include "../../gfx/Box.h"
#include "../../gfx/Gfx.h"
#include "../../gfx/Line.h"
#include "../../gfx/Circle.h"
#include "../../gfx/Bullet.h"
#include "../EntityManager.h"
#include "../component/Transform.h"

PrimitiveRenderSystem::PrimitiveRenderSystem() {
	this->renderer = Gfx::getInstance()->getRenderer();
}

void PrimitiveRenderSystem::update(Camera* camera) {
	renderLine(camera);
	renderBox(camera);
    renderCircle(camera);
	renderBullet();
}

void PrimitiveRenderSystem::renderLine(Camera* camera) {
	auto entities = EntityManager::getInstance()->getEntitiesWithComponent<Line>();
	sort(entities.begin(), entities.end(), Line::compareAsc);

	for (auto& entity : entities) {
		Line* line = entity->getComponent<Line>();
		Transform* transform = entity->getComponent<Transform>();
		auto dimension = line->getSize();
		auto lW = dimension.w;
		auto lH = dimension.h;

		if (line && transform) {
			bool isOutsideCameraView = (
				transform->position.x + (transform->scale.x * lW) < camera->x ||
				transform->position.x > camera->x + camera->w ||
				transform->position.y + (transform->scale.y * lH) < camera->y ||
				transform->position.y > camera->y + camera->h
			);

			if (isOutsideCameraView && !line->isFixed) {
                continue;
            }

			auto x0 = static_cast<int>(transform->position.x - (line->isFixed ? 0 : camera->x)); 
			auto y0 = static_cast<int>(transform->position.y - (line->isFixed ? 0 : camera->y));
			auto x1 = static_cast<int>(line->b.x * transform->scale.x); 
			auto y1 = static_cast<int>(line->b.y * transform->scale.y);
			
            Gfx::getInstance()->drawLine(x0, y0, x1, y1, line->color);
		}
	}
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
			auto r = static_cast<int>(circle->getRadius() * transform->scale.x);
	
			if (!circle->isDashed) {
            	Gfx::getInstance()->drawCircle(x, y, r, circle->color);
			} else {
				Gfx::getInstance()->drawDashedCircle(x, y, r, circle->dashLength, circle->color);
			}
		}
	}
}

void PrimitiveRenderSystem::renderBullet() {
	auto entities = EntityManager::getInstance()->getEntitiesWithComponent<Bullet>();

	for (auto& entity : entities) {
		Bullet* bullet = entity->getComponent<Bullet>();
		Transform* transform = entity->getComponent<Transform>();
		
		if (bullet && transform) {
			auto x0 = static_cast<int>(bullet->originX);
			auto y0 = static_cast<int>(bullet->originY);
			
			float lineLength = bullet->size;

			auto x1 = static_cast<int>(x0 + bullet->directionX * lineLength); 
			auto y1 = static_cast<int>(y0 + bullet->directionY * lineLength);

			Gfx::getInstance()->drawLine(x0, y0, x1, y1, bullet->color);
		}
	}
}
