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

        if (rigidBody && transform) {
            Waypoint* points = entity->getComponent<Waypoint>();
            if (!points->waypoints.empty()) {

                // Get the current waypoint
                std::pair<int, int> currentWaypoint = points->waypoints.front();

                int dx = currentWaypoint.first - transform->position.x;
                int dy = currentWaypoint.second - transform->position.y;

                // Calculate the distance to the waypoint
                float distance = std::sqrt(dx * dx + dy * dy);

                // Normalize the direction vector
                float directionX = dx / distance;
                float directionY = dy / distance;

                // Define the movement speed
                float speedX = rigidBody->velocity.x;
                float speedY = rigidBody->velocity.y;

                // Calculate the movement distances based on the speeds and delta time
                float movementDistanceX = speedX * dt;
                float movementDistanceY = speedY * dt;

                // Move the entity towards the waypoint
                transform->position.x += movementDistanceX * directionX;
                transform->position.y += movementDistanceY * directionY;

                // Check if the entity has reached the waypoint
                if (distance <= std::sqrt(movementDistanceX * movementDistanceX + movementDistanceY * movementDistanceY)) {
                    // Remove the current waypoint from the list
                    points->waypoints.erase(points->waypoints.begin());
                }
            }
        }
    }      
}
