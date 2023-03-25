/*
	Windows 10 - 11
	SchumakerTeam
	Hudson Schumaker
*/

#pragma once
#include "../include/Common.h"

class Map final {
public:
	short assertId = 0;
	std::string mapId = "";
	short tileSize = 0;
	float scale = 1.0f;
	short mapNumCols = 0;
	short mapNumRows = 0;
	int mapWidth = 0;
	int mapHeight = 0;

	Map() {}
	Map(short assertId, std::string mapId, short tileSize, float scale, short mapNumCols, short mapNumRows) {
		this->assertId = assertId;
		this->mapId = mapId;
		this->tileSize = tileSize;
		this->scale = scale;
		this->mapNumCols = mapNumCols;
		this->mapNumRows = mapNumRows;

		// update map dimension
		this->mapWidth = mapNumCols * tileSize * scale;
		this->mapHeight = mapNumRows * tileSize * scale;
	}

	~Map() = default;
};