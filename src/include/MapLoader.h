/*
	SchumakerTeam
	Hudson Schumaker
*/

#pragma once
#include "Common.h"
#include "Map.h"

class MapLoader final {
public:
	MapLoader() = default;
	~MapLoader() = default;
	
	void loadMap(Map map);
};