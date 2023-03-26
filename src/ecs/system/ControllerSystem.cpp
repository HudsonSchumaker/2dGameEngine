/*
	SchumakerTeam
	Hudson Schumaker
*/

#include "ControllerSystem.h"
#include "../EntityManager.h"
#include "../../event/EventBus.h"
#include "../../gfx/Animation.h"
#include "../component/Transform.h"
#include "../component/RigidBody.h"
#include "../component/Controller.h"

ControllerSystem::ControllerSystem() {
	subscribeToEvents();
}

void ControllerSystem::subscribeToEvents() {
	EventBus::getInstance()->subscribeToEvent<KeyPressedEvent>(this, &ControllerSystem::onKeyPressed);
    EventBus::getInstance()->subscribeToEvent<KeyReleasedEvent>(this, &ControllerSystem::onKeyReleased);
    EventBus::getInstance()->subscribeToEvent<JoyPadLeftAxisEvent>(this, &ControllerSystem::joypadLeftAxis);
}

void ControllerSystem::joypadLeftAxis(JoyPadLeftAxisEvent& event) {
    auto entities = EntityManager::getInstance()->getEntitiesWithComponent<Controller>();

    for (auto& entity : entities) {
        RigidBody* rigidBody = entity->getComponent<RigidBody>();
        Controller* controller = entity->getComponent<Controller>();
        Animation* animation = entity->getComponent<Animation>();

        if (animation) {
            if (event.axis.x < 0.0f) {
                animation->flip = true;
            }
            else {
                animation->flip = false;
            }
        }

        if (rigidBody && controller) {
            rigidBody->velocity.x = controller->velocity.x * event.axis.x;
            rigidBody->velocity.y = controller->velocity.y * event.axis.y;
        }
    }
}

void ControllerSystem::onKeyPressed(KeyPressedEvent& event) {
	auto entities = EntityManager::getInstance()->getEntitiesWithComponent<Controller>();
	
	for (auto& entity : entities) {
		RigidBody* rigidBody = entity->getComponent<RigidBody>();
        Controller* controller = entity->getComponent<Controller>();

        switch (event.symbol) {
        case SDLK_UP:
            rigidBody->velocity.y = -controller->velocity.y;
            break;
        case SDLK_RIGHT:
            rigidBody->velocity.x = controller->velocity.x;
            break;
        case SDLK_DOWN:
            rigidBody->velocity.y = controller->velocity.y;
            break;
        case SDLK_LEFT:
            rigidBody->velocity.x = -controller->velocity.x;
            break;
        }
	}
}

void ControllerSystem::onKeyReleased(KeyReleasedEvent& event) {
    auto entities = EntityManager::getInstance()->getEntitiesWithComponent<Controller>();

    for (auto& entity : entities) {
        RigidBody* rigidBody = entity->getComponent<RigidBody>();
        Controller* controller = entity->getComponent<Controller>();

        switch (event.symbol) {
        case SDLK_UP:
            rigidBody->velocity.y = 0.0f;
            break;
        case SDLK_RIGHT:
            rigidBody->velocity.x = 0.0f;
            break;
        case SDLK_DOWN:
            rigidBody->velocity.y = 0.0f;
            break;
        case SDLK_LEFT:
            rigidBody->velocity.x = 0.0f;
            break;
        }
    }
}
