/*
	SchumakerTeam
	Hudson Schumaker
*/

#pragma once
#include "Component.h"
#include "Transform.h"
#include "../EntityManager.h"

class Button final : public Component {
public:
    short hover = 8;
    bool isHover = false;
    
    Button() {}
    Button(short hover) {
        this->hover = hover;
    }
    
    Button(short hover, bool isHover) {
        this->hover = hover;
        this->isHover = isHover;
    }
    ~Button() = default;

    void hoverOn() {
        if (isHover == false) {
            Entity* parent = EntityManager::getInstance()->getEntity(parentId);
            Transform* parentTransform = parent->getComponent<Transform>();
            
            if(parentTransform) {
                parentTransform->position.y -= hover;
                isHover = true;
            }
        }
    }
    
    void hoverOff() {
        if (isHover) {
            Entity* parent = EntityManager::getInstance()->getEntity(parentId);
            Transform* parentTransform = parent->getComponent<Transform>();
            
            if(parentTransform) {
                parentTransform->position.y += hover;
                isHover = false;
            }
        }
    }
};
