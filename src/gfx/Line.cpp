/*
	Dodoi Lab
	Dodoi Engine
	Hudson Schumaker
*/

#include "Gfx.h"
#include "Line.h"
#include "../ecs/EntityManager.h"
#include "../ecs/component/Transform.h"

Dimension Line::getSize() const {
    double x1 = a.x;
    double y1 = a.y;
    double x2 = b.x;
    double y2 = b.y;

    double length = std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
	return Dimension(length, 2);
}

bool Line::compareAsc(Entity* e1, Entity* e2) {
	return (e1->getComponent<Line>()->layer < e2->getComponent<Line>()->layer);
}

bool Line::compareDesc(Entity* e1, Entity* e2) {
	return (e1->getComponent<Line>()->layer > e2->getComponent<Line>()->layer);
}
    