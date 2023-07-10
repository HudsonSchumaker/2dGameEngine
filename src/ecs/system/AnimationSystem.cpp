/*
	Dodoi Lab
	Dodoi Engine
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

void AnimationSystem::update(Camera* camera) {
    auto entities = EntityManager::getInstance()->getEntitiesWithComponent<Animation>();
    sort(entities.begin(), entities.end(), Animation::compareAsc);

    for (auto& entity : entities) {
        Animation* animation = entity->getComponent<Animation>();
        Transform* transform = entity->getComponent<Transform>();

        if (animation && transform) {
            animation->currentFrame = ((SDL_GetTicks() - animation->startTime)
                * animation->frameSpeedRate / 1000) % animation->numFrames;
            
            SDL_Rect origin = { animation->currentFrame * animation->getSize().w, 0,
                animation->getSize().h, animation->getSize().h };

            SDL_FRect dest;
            dest.x = transform->position.x - (animation->isFixed ? 0 : camera->x);
            dest.y = transform->position.y - (animation->isFixed ? 0 : camera->y);
            dest.w = animation->getSize().w * transform->scale.x;
            dest.h = animation->getSize().h * transform->scale.y;
            
            if (animation->flip) {
                SDL_RenderCopyExF(
                    renderer, 
                    animation->texture, 
                    &origin, 
                    &dest, 
                    transform->rotation, 
                    NULL, 
                    SDL_FLIP_HORIZONTAL);
            }
            else {
                SDL_RenderCopyExF(
                    renderer, 
                    animation->texture, 
                    &origin, 
                    &dest, 
                    transform->rotation, 
                    NULL, 
                    SDL_FLIP_NONE);
            }
        }
    }
}
