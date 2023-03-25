/*
	Windows 10 - 11
	SchumakerTeam
	Hudson Schumaker
*/

#include "CameraMovementSystem.h"
#include "../EntityManager.h"
#include "../component/Transform.h"
#include "../component/CameraFollow.h"

void CameraMovementSystem::update(Map* map, Camera* camera) {
	auto entities = EntityManager::getInstance()->getEntitiesWithComponent<CameraFollow>();

	for (auto& entity : entities) {
		CameraFollow* cameraFollow = entity->getComponent<CameraFollow>();
		Transform* transform = entity->getComponent<Transform>();

		if (cameraFollow && transform) {
			if (transform->position.x + (camera->w / 2) < map->mapWidth) {
				camera->x = transform->position.x - SCREEN_H_WIDTH;
			}

			if (transform->position.y + (camera->h / 2) < map->mapHeight) {
				camera->y = transform->position.y - SCREEN_H_HEIGHT;
			}

			// Keep camera rectangle view inside the screen limits
			camera->x = camera->x < 0 ? 0 : camera->x;
			camera->y = camera->y < 0 ? 0 : camera->y;
			
			camera->x = (camera->x + camera->w > map->mapWidth) ?
				map->mapWidth - camera->w : camera->x;
			
			camera->y = (camera->y + camera->h > map->mapHeight) ?
				map->mapHeight - camera->h : camera->y;
		}
	}
}
