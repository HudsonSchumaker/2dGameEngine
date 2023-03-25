/*
	Windows 10 - 11
	SchumakerTeam
	Hudson Schumaker
*/

#include "RenderSystem.h"
#include "../../gfx/Gfx.h"
#include "../EntityManager.h"
#include "../../gfx/Sprite.h"
#include "../component/Transform.h"

RenderSystem::RenderSystem() {
	this->renderer = Gfx::getInstance()->getRenderer();
}

void RenderSystem::update(Camera* camera) {
	auto entities = EntityManager::getInstance()->getEntitiesWithComponent<Sprite>();
	sort(entities.begin(), entities.end(), Sprite::compareAsc);

	for (auto& entity : entities) {
		Sprite* sprite = entity->getComponent<Sprite>();
		Transform* transform = entity->getComponent<Transform>();

		if (sprite && transform) {
			SDL_Rect srcRect = sprite->srcRect;
			SDL_FRect dstRect = {
				transform->position.x - (sprite->isFixed ? 0 : camera->x), 
				transform->position.y - (sprite->isFixed ? 0 : camera->y),
				sprite->w * transform->scale.x,
				sprite->h * transform->scale.y
			};

			SDL_RenderCopyExF(
				renderer,
				sprite->texture,
				&srcRect,
				&dstRect,
				transform->rotation,
				NULL,
				SDL_FLIP_NONE);
		}
	}
}
