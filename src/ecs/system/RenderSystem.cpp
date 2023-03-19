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

void RenderSystem::update(float dt) {
	auto entities = EntityManager::getInstance()->getEntitiesWithComponent<Sprite>();
	sort(entities.begin(), entities.end(), Sprite::compareAsc);

	for (auto& entity : entities) {
		Sprite* renderable = entity->getComponent<Sprite>();
		Transform* transform = entity->getComponent<Transform>();

		if (renderable && transform) {
			renderable->rect.x = transform->position.x;
			renderable->rect.y = transform->position.y;

			renderable->rect.w = renderable->w * transform->scale.x;
			renderable->rect.h = renderable->h * transform->scale.y;

			SDL_RenderCopyF(renderer, renderable->texture, nullptr, &renderable->rect);
		}
	}
}