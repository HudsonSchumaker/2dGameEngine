/*
	Dodoi Lab
	Dodoi Engine
	Hudson Schumaker
*/

#pragma once
#include "Component.h"
#include "Transform.h"
#include "../../gfx/Scene.h"
#include "../EntityManager.h"

class Button : public Component {
public:
    typedef std::function<void(unsigned long, int)> Callback;
    short hover = 8;
    bool isHover = false;
    
    Button() {
        callback_ = nullptr;
    }

    Button(const Callback& callback) {
        callback_ = callback;
    }

    Button(const Callback& callback, short hover) {
        callback_ = callback;
        this->hover = hover;
    }
    
    Button(const Callback& callback, short hover, bool isHover) {
        callback_ = callback;
        this->hover = hover;
        this->isHover = isHover;
    }

    ~Button() = default;

    void setCallback(const Callback& callback) {
       callback_ = callback;
    }

    void onClick(unsigned long id, int value) {
       if (callback_) {
           callback_(id, value);
       }
    }

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

private:
    Callback callback_;
};
