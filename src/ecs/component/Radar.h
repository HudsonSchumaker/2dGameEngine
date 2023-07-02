/*
	Dodoi Lab
	Dodoi Engine
	Hudson Schumaker
*/

#pragma once
#include "Component.h"
#include "../Tag.h"
#include "../../physics/Vec2.h"

class Radar final : public Component {
public:
    short r = 2;
    Tag tag = Tag::enemy;
    Vec2 offset;

    Radar(short radius) : r(radius) {}
    Radar(short radius, Tag tag) : r(radius), tag(tag) {}
    Radar(short radius, Vec2 offset) : r(radius), offset(offset) {}
    Radar(short radius, Tag tag, Vec2 offset) : r(radius), tag(tag), offset(offset) {}
};
