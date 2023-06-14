/*
	Dodoi Lab
	Dodoi Engine
	Hudson Schumaker
*/

#include "Gfx.h"
#include "Box.h"
#include "AssetManager.h"
#include "../ecs/EntityManager.h"
#include "../ecs/component/Transform.h"

Box::Box() {
    w = 2;
    h = 2;
}

Box::Box(int w, int h) {
    this->w = w;
    this->h = h;
}

Box::Box(int w, int h, short layer) {
    this->w = w;
    this->h = h;
    this->layer = layer;
}

Box::Box(int w, int h, short layer, bool isFixed) {
    this->w = w;
    this->h = h;
    this->layer = layer;
    this->isFixed = isFixed;
}

void Box::setOnCenter() {
	auto parent = EntityManager::getInstance()->getEntity(parentId);
	auto transform = parent->getComponent<Transform>();
	if (transform) {
		transform->position.x = SCREEN_H_WIDTH - (w/2);
		transform->position.y = SCREEN_H_HEIGHT - (h/2);
	}
}

void Box::setOnCenterX() {
	auto parent = EntityManager::getInstance()->getEntity(parentId);
	auto transform = parent->getComponent<Transform>();
	if (transform) {
		transform->position.x = SCREEN_H_WIDTH - (w/2);
	}
}

void Box::setOnCenterY() {
	auto parent = EntityManager::getInstance()->getEntity(parentId);
	auto transform = parent->getComponent<Transform>();
	if (transform) {
		transform->position.y = SCREEN_H_HEIGHT - (h/2);
	}
}

Dimension Box::getSize() const {
	return Dimension(w, h);
}

bool Box::compareAsc(Entity* e1, Entity* e2) {
	return (e1->getComponent<Box>()->layer < e2->getComponent<Box>()->layer);
}

bool Box::compareDesc(Entity* e1, Entity* e2) {
	return (e1->getComponent<Box>()->layer > e2->getComponent<Box>()->layer);
}
