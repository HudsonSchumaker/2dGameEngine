/*
	Dodoi Lab
	Dodoi Engine
	Hudson Schumaker
*/

#include "RenderTextSystem.h"
#include "../../gfx/Gfx.h"
#include "../EntityManager.h"
#include "../component/TextLabel.h"
#include "../component/Transform.h"
#include "../component/SpriteText.h"

RenderTextSystem::RenderTextSystem() {
	this->renderer = Gfx::getInstance()->getRenderer();
}

void RenderTextSystem::update(Camera* camera) {
	renderTextLabel(camera);
	renderSpriteText(camera);
}

void RenderTextSystem::renderTextLabel(Camera* camera) {
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

void RenderTextSystem::renderSpriteText(Camera* camera) {
	auto entities = EntityManager::getInstance()->getEntitiesWithComponent<SpriteText>();

	for (auto& entity : entities) {
		Transform* transform = entity->getComponent<Transform>();
		SpriteText* spriteText = entity->getComponent<SpriteText>();

		if (transform && spriteText) {
			int newX = transform->position.x + spriteText->offSet.x;
			int newY = transform->position.y + spriteText->offSet.y; 

			spriteText->position.x = newX;
			spriteText->position.y = newY;

			SDL_Rect dstRect = {
				static_cast<int>(spriteText->position.x - (spriteText->isFixed ? 0 : camera->x)),
				static_cast<int>(spriteText->position.y - (spriteText->isFixed ? 0 : camera->y)),
				spriteText->w,
				spriteText->h
			};
			
			// TODO: why not using Gfx?
			SDL_RenderCopy(renderer, spriteText->label, NULL, &dstRect);
		}
	}
}
