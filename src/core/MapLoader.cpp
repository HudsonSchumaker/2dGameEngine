/*
	SchumakerTeam
	Hudson Schumaker
*/

#include "../include/MapLoader.h"
#include "../include/Sprite.h"
#include "../include/AssetManager.h"
#include "../include/EntityManager.h"
#include "../include/RigidBody.h"
#include "../include/Transform.h"
#include "../include/BoxCollider.h"

void MapLoader::loadMap(Map map) {
	std::fstream mapFile;
	auto path = MAP_FOLDER + map.mapId;
	mapFile.open(path);

	for (short y = 0; y < map.mapNumRows; y++) {
		for (short x = 0; x < map.mapNumCols; x++) {
			char ch;

			mapFile.get(ch);
			int srcRectY = std::atoi(&ch) * map.tileSize;			
			mapFile.get(ch);
			int srcRectX = std::atoi(&ch) * map.tileSize;
			
			mapFile.get(ch);
			char collider = ch;
			mapFile.ignore();

			auto e = EntityManager::getInstance()->createEntity(
				x * map.scale * map.tileSize, 
				y * map.scale * map.tileSize
			);
			e->getComponent<Transform>()->scale.x = map.scale;
			e->getComponent<Transform>()->scale.y = map.scale;
			e->tag = Tag::tile;
			e->addComponent(new Sprite(map.assertId, srcRectX, srcRectY,
				map.tileSize, map.tileSize, (int)Tag::tile));

			if (collider == 'C') {
				e->addComponent(new BoxCollider(0, 0, map.tileSize, map.tileSize));
			}
		}
	}
}
