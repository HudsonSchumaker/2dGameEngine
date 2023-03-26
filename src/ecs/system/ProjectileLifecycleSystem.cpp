/*
    SchumakerTeam
    Hudson Schumaker
*/

#include "ProjectileLifecycleSystem.h"
#include "../EntityManager.h"
#include "../component/Projectile.h"

void ProjectileLifecycleSystem::update() {
    auto entities = EntityManager::getInstance()->getEntitiesWithComponent<Projectile>();

    for (auto& entity : entities) {
        Projectile* projectile = entity->getComponent<Projectile>();
        if (projectile) {
            if ((SDL_GetTicks() - projectile->startTime) > projectile->duration) {
                EntityManager::getInstance()->killEntity(entity);
            }
        }
    }
}
