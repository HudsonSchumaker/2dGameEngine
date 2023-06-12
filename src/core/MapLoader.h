/*
	SchumakerTeam
	Dodoi Engine
	Hudson Schumaker
*/

#pragma once
#include "../include/Common.h"
#include "../core/Map.h"

class MapLoader final {
public:
	MapLoader() = default;
	~MapLoader() = default;
	
	void loadMap(Map map);
};