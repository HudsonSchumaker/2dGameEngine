/*
	Dodoi Lab
	Dodoi Engine
	Hudson Schumaker
*/

#include "RenderHealthBarSystem.h"
#include "../../gfx/Gfx.h"
#include "../../gfx/Box.h"
#include "../../gfx/Line.h"
#include "../../gfx/Circle.h"
#include "../EntityManager.h"
#include "../../gfx/Sprite.h"
#include "../../gfx/Animation.h"
#include "../component/Health.h"
#include "../component/Transform.h"

RenderHealthBarSystem::RenderHealthBarSystem() {
	this->renderer = Gfx::getInstance()->getRenderer();
}

void RenderHealthBarSystem::update(Camera* camera) {
	auto entities = EntityManager::getInstance()->getEntitiesWithComponent<Health>();

	for (auto& entity : entities) {
		Transform* transform = entity->getComponent<Transform>();
		Health* health = entity->getComponent<Health>();

		if (transform && health) {
			SDL_Color healthBarColor = { 255, 255, 255 };

            if (health->healthPercentage >= 0 && health->healthPercentage < 40) {
                healthBarColor = { 255, 0, 0 }; // 0-40 = red
            }
            if (health->healthPercentage >= 40 && health->healthPercentage < 80) {
                healthBarColor = { 255, 255, 0 }; // 40-80 = yellow
            }
            if (health->healthPercentage >= 80 && health->healthPercentage <= 100) {
                healthBarColor = { 0, 255, 0 }; // 80-100 = green
            }

            // Position the health bar indicator in the top-right part of the entity sprite
            int healthBarWidth = 15;
            int healthBarHeight = 3;

            // Get width of the "renderable" component
			int entityWidth = getWidth(entity);	

            double healthBarPosX = (transform->position.x + (entityWidth * transform->scale.x)) - camera->x;
            double healthBarPosY = (transform->position.y) - camera->y;

            SDL_Rect healthBarRectangle = {
                static_cast<int>(healthBarPosX),
                static_cast<int>(healthBarPosY),
                static_cast<int>(healthBarWidth * (health->healthPercentage / 100.0)),
                static_cast<int>(healthBarHeight)
            };
            SDL_SetRenderDrawColor(renderer, healthBarColor.r, healthBarColor.g, healthBarColor.b, 255);
            SDL_RenderFillRect(renderer, &healthBarRectangle);

            // Render the health percentage text label indicator
            std::string healthText = std::to_string(health->healthPercentage);
			SDL_Texture* texture = Gfx::getInstance()->createText("pico8.ttf", healthText.c_str(), 5, healthBarColor);

            int labelWidth = 0;
            int labelHeight = 0;
            SDL_QueryTexture(texture, NULL, NULL, &labelWidth, &labelHeight);
            SDL_Rect healthBarTextRectangle = {
                static_cast<int>(healthBarPosX),
                static_cast<int>(healthBarPosY) + 5,
                labelWidth,
                labelHeight
            };
                
            SDL_RenderCopy(renderer, texture, NULL, &healthBarTextRectangle);
            SDL_DestroyTexture(texture);
		}
	}
}

float RenderHealthBarSystem::getWidth(Entity* entity) {
    Line* line = entity->getComponent<Line>();
    if (line) {
        return line->getSize().w;
    }

    Box* box = entity->getComponent<Box>();
    if (box) {
        return box->w;
    }

    Circle* circle = entity->getComponent<Circle>();
    if (circle) {
        return circle->getSize().w;
    }

    Sprite* sprite = entity->getComponent<Sprite>();
    if (sprite) {
        return sprite->w;
    }

    Animation* animation = entity->getComponent<Animation>();
    if (animation) {
        return animation->getSize().w;
    }

    return 1.0f;
}
