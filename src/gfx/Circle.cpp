/*
	Dodoi Lab
	Dodoi Engine
	Hudson Schumaker
*/

#include "Gfx.h"
#include "Circle.h"
#include "AssetManager.h"
#include "../ecs/EntityManager.h"
#include "../ecs/component/Transform.h"

Dimension Circle::getSize() const {
    int sideLength = sqrt(2) * r;
	return Dimension(sideLength, sideLength);
}

bool Circle::compareAsc(Entity* e1, Entity* e2) {
	return (e1->getComponent<Circle>()->layer < e2->getComponent<Circle>()->layer);
}

bool Circle::compareDesc(Entity* e1, Entity* e2) {
	return (e1->getComponent<Circle>()->layer > e2->getComponent<Circle >()->layer);
}
