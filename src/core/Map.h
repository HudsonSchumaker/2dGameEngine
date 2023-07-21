/*
	SchumakerTeam
	Dodoi Engine
	Hudson Schumaker
*/

#pragma once
#include "../include/Common.h"

class Map final {
public:
	std::string assetId = "";
	std::string mapId = "";
	short tileSize = 0;
	float scale = 1.0f;
	short mapNumCols = 0;
	short mapNumRows = 0;
	int mapWidth = 0;
	int mapHeight = 0;

	Map() {}

	/// <summary>
	/// Map constructor
	/// </summary>
	/// <param name="name">The asset ID of the map</param>
	/// <param name="mapId">The unique ID of the map</param>
	/// <param name="tileSize">The size of each tile in the map</param>
	/// <param name="scale">The scale of the map</param>
	/// <param name="mapNumCols">The number of columns in the map</param>
	/// <param name="mapNumRows">The number of rows in the map</param>
	Map(const std::string& name, std::string mapId, short tileSize, float scale, short mapNumCols, short mapNumRows) {
		this->assetId = name;
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
