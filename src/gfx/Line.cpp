/*
	Dodoi Lab
	Dodoi Engine
	Hudson Schumaker
*/

#include "Gfx.h"
#include "Line.h"
#include "../physics/DMath.h"
#include "../ecs/EntityManager.h"
#include "../ecs/component/Transform.h"

Dimension Line::getSize() const {
	auto parent = EntityManager::getInstance()->getEntity(parentId);
	auto transform = parent->getComponent<Transform>();
	if (transform) {
		double x1 = transform->position.x;
    	double y1 = transform->position.y;
    	double x2 = b.x;
    	double y2 = b.y;

    	double length = DMath::rootd(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
		return Dimension(length, 2);
	}
	
	return Dimension(0, 0);
}

bool Line::compareAsc(Entity* e1, Entity* e2) {
	return (e1->getComponent<Line>()->layer < e2->getComponent<Line>()->layer);
}

bool Line::compareDesc(Entity* e1, Entity* e2) {
	return (e1->getComponent<Line>()->layer > e2->getComponent<Line>()->layer);
}
    