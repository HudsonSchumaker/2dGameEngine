/*
	Dodoi Lab
	Dodoi Engine
	Hudson Schumaker
*/

#pragma once
#include "../gfx/Color.h"
#include "../ecs/Entity.h"
#include "../physics/Vec2.h"
#include "../physics/Dimension.h"
#include "../ecs/component/Component.h"

class Bullet : public Component {
public:
    float originX = 0.0f;
    float originY = 0.0f;
    float directionX = 1.0f;
    float directionY = 1.0f;
    float destinationX = 1.0f;
    float destinationY = 1.0f;
    
    float size = 2.0f;
    float magnitude = 0.0f;

    short layer = 10;
    bool isFixed = false;
    SDL_Color color = Color::getOrange();

    Bullet(Vec2 destination) {
        auto parent = EntityManager::getInstance()->getEntity(parentId);
	    auto transform = parent->getComponent<Transform>();
        originX = transform->position.x;
        originY = transform->position.y;
        destinationX = destination.x;
        destinationY = destination.y;
        
        calculate();
    };
    ~Bullet() = default;

    void calculate() {
        float dx = destinationX - originX;
        float dy = destinationY - originY;
        magnitude = std::sqrt(dx * dx + dy * dy);
        directionX = dx / magnitude;
        directionY = dy / magnitude;
    }

    Dimension getDimension() const { 
        return Dimension(size, 2);
    }
};
