/*
	Dodoi Lab
	Dodoi Engine
	Hudson Schumaker
*/

#pragma once
#include "Component.h"

class Waypoint final : public Component { 
public:
    std::vector<std::pair<short, short>> waypoints;

    Waypoint(const std::vector<std::pair<short, short>>& points) : waypoints(points) {}
    ~Waypoint() = default;
};
