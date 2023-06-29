/*
	Dodoi Lab
	Dodoi Engine
	Hudson Schumaker
*/

#pragma once
#include "Component.h"

class Radar final : public Component {
public:
    short r = 2;
    short tag = 3;

    Radar(short radius) : r(radius) {}
    Radar(short radius, short tag) : r(radius), tag(tag) {}
};
