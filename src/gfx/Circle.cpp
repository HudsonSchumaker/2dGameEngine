/*
	Dodoi Lab
	Dodoi Engine
	Hudson Schumaker
*/

#include "Gfx.h"
#include "Circle.h"
#include "../physics/DMath.h"
#include "../ecs/EntityManager.h"
#include "../ecs/component/Transform.h"

void Circle::sideCalculation() {
    side = DMath::rootf(2) * r;
}

Dimension Circle::getSize() const {
	return Dimension(side, side);
}

bool Circle::compareAsc(Entity* e1, Entity* e2) {
	return (e1->getComponent<Circle>()->layer < e2->getComponent<Circle>()->layer);
}

bool Circle::compareDesc(Entity* e1, Entity* e2) {
	return (e1->getComponent<Circle>()->layer > e2->getComponent<Circle >()->layer);
}
