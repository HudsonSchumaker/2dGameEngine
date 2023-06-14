/*
	SchumakerTeam
	Hudson Schumaker
*/

#include "RenderTextSystem.h"
#include "../../gfx/Gfx.h"
#include "../EntityManager.h"
#include "../component/TextLabel.h"
#include "../component/Transform.h"

RenderTextSystem::RenderTextSystem() {
	this->renderer = Gfx::getInstance()->getRenderer();
}

void RenderTextSystem::update(Camera* camera) {
	auto entities = EntityManager::getInstance()->getEntitiesWithComponent<TextLabel>();

	for (auto& entity : entities) {
		TextLabel* textLabel = entity->getComponent<TextLabel>();
		
		if (textLabel) {
			SDL_Rect dstRect = {
				static_cast<int>(textLabel->position.x - (textLabel->isFixed ? 0 : camera->x)),
				static_cast<int>(textLabel->position.y - (textLabel->isFixed ? 0 : camera->y)),
				textLabel->w,
				textLabel->h
			};
			
			// TODO: why not using Gfx?
			SDL_RenderCopy(renderer, textLabel->label, NULL, &dstRect);
		}
	}
}
