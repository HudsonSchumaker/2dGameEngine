/*
	Dodoi Lab
	Dodoi Engine
	Hudson Schumaker
*/

# include "WaypointNavigationSystem.h"
#include "../EntityManager.h"
#include "../component/Waypoint.h"
#include "../component/Transform.h"
#include "../component/RigidBody.h"

void WaypointNavigationSystem::update(float dt) {
    auto entities = EntityManager::getInstance()->getEntitiesWithComponent<Waypoint>();

    for (auto& entity : entities) {
        RigidBody* rigidBody = entity->getComponent<RigidBody>();
        Transform* transform = entity->getComponent<Transform>();
        Waypoint* points = entity->getComponent<Waypoint>();

        if (rigidBody && transform && !points->waypoints.empty()) {
            // Get the current waypoint
            std::pair<int, int> currentWaypoint = points->waypoints.front();

            // Calculate the direction vector
            float dx = currentWaypoint.first - transform->position.x;
            float dy = currentWaypoint.second - transform->position.y;
            float distance = std::sqrt(dx * dx + dy * dy);

            // Check if the entity has reached the waypoint
            if (distance <= 1.0f) {
                // Remove the current waypoint from the list
                points->waypoints.erase(points->waypoints.begin());
            } else {
                // Normalize the direction vector
                float directionX = dx / distance;
                float directionY = dy / distance;

                // Calculate the movement distances based on the speeds and delta time
                float movementDistanceX = rigidBody->velocity.x * dt;
                float movementDistanceY = rigidBody->velocity.y * dt;

                // Move the entity towards the waypoint
                transform->position.x += movementDistanceX * directionX;
                transform->position.y += movementDistanceY * directionY;
            }
        }
    }      
    
}
