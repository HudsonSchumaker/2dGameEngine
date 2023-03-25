/*
    Windows 10 - 11
    SchumakerTeam
    Hudson Schumaker
*/

#include "ProjectileEmitSystem.h"
#include "../EntityManager.h"
#include "../../gfx/Animation.h"
#include "../../event/EventBus.h"
#include "../component/Transform.h"
#include "../component/RigidBody.h"
#include "../../core/BulletFactory.h"
#include "../component/ProjectileEmitter.h"

ProjectileEmitSystem::ProjectileEmitSystem() {
    subscribeToEvents();
}

void ProjectileEmitSystem::subscribeToEvents() {
    EventBus::getInstance()->subscribeToEvent<FireEvent>(this, &ProjectileEmitSystem::onFire);
}

void ProjectileEmitSystem::onFire(FireEvent& event) {
    auto entities = EntityManager::getInstance()->getEntitiesWithTag(event.tag);
    for (auto& entity : entities) {
        RigidBody* rigidBody = entity->getComponent<RigidBody>();
        Transform* transform = entity->getComponent<Transform>();
        Animation* animation = entity->getComponent<Animation>();
        ProjectileEmiter* emiter = entity->getComponent<ProjectileEmiter>();

        if (rigidBody && transform && animation && emiter) {
            auto bullet = BulletFactory::getInstance()->createBullet(emiter->bulletType, true);
            auto bulletTransform = bullet->getComponent<Transform>();
            if (animation->flip) {
                auto bulletRigidBody = bullet->getComponent<RigidBody>();
                bulletRigidBody->velocity.x *= -1.0f;
                bulletTransform->position.x = transform->position.x - animation->bounds.x;
            }
            else {
                bulletTransform->position.x = transform->position.x + animation->bounds.x;
            }

            bulletTransform->position.y = transform->position.y + (animation->bounds.y /2.0f);
        }
    }
}
