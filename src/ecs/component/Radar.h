/*
	Dodoi Lab
	Dodoi Engine
	Hudson Schumaker
*/

#pragma once
#include "Component.h"
#include "../Tag.h"

class Radar final : public Component {
public:
    short r = 2;
    Tag tag = Tag::enemy;

    Radar(short radius) : r(radius) {}
    Radar(short radius, Tag tag) : r(radius), tag(tag) {}
};
