/*
    Windows 10 - 11
    SchumakerTeam
    Hudson Schumaker
*/

#include "AnimationSystem.h"
#include "../../gfx/Gfx.h"
#include "../EntityManager.h"
#include "../../gfx/Animation.h"
#include "../component/Transform.h"

AnimationSystem::AnimationSystem() {
	this->renderer = Gfx::getInstance()->getRenderer();
}

void AnimationSystem::update(float dt) {
    auto entities = EntityManager::getInstance()->getEntitiesWithComponent<Animation>();
    sort(entities.begin(), entities.end(), Animation::compareAsc);

    for (auto& entity : entities) {
        Animation* animation = entity->getComponent<Animation>();
        Transform* transform = entity->getComponent<Transform>();

        if (animation && transform) {
            animation->currentFrame = ((SDL_GetTicks() - animation->startTime)
                * animation->frameSpeedRate / 1000) % animation->numFrames;

            SDL_Rect origin = { animation->currentFrame * animation->bounds.x, 0,
                animation->bounds.x, animation->bounds.y };

            SDL_FRect dest;
            dest.x = transform->position.x;
            dest.y = transform->position.y;
            dest.w = animation->bounds.x * transform->scale.x;
            dest.h = animation->bounds.y * transform->scale.y;
            
            if (animation->flip) {
                SDL_RenderCopyExF(renderer, animation->texture, &origin, &dest, 0.0, NULL, SDL_FLIP_HORIZONTAL);
            }
            else {
                SDL_RenderCopyExF(renderer, animation->texture, &origin, &dest,0.0, NULL, SDL_FLIP_NONE);
            }
        }
    }
}