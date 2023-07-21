/*
	SchumakerTeam
	Dodoi Engine
	Hudson Schumaker
*/

#include "MapLoader.h"
#include "../gfx/Sprite.h"
#include "../gfx/AssetManager.h"
#include "../ecs/EntityManager.h"
#include "../ecs/component/RigidBody.h"
#include "../ecs/component/Transform.h"
#include "../ecs/component/BoxCollider.h"

void MapLoader::loadMap(Map map) {
    std::fstream mapFile;
    auto path = MAP_FOLDER + map.mapId + ".map";

    // Open the map file
    mapFile.open(path);

    // Iterate over each row and column of the map
    for (short y = 0; y < map.mapNumRows; y++) {
        for (short x = 0; x < map.mapNumCols; x++) {
            char ch = 0;

            // Read the character from the map file to determine the source rectangle position
            mapFile.get(ch);
            int srcRectY = std::atoi(&ch) * map.tileSize;			
            mapFile.get(ch);
            int srcRectX = std::atoi(&ch) * map.tileSize;

            // Read the character representing the collider type
            mapFile.get(ch);
            char collider = ch;
            mapFile.ignore();

            // Create an entity for the tile at the current position
            auto e = EntityManager::getInstance()
				->createEntity(x * map.scale * map.tileSize, 
                               y * map.scale * map.tileSize);
            
            // Set the entity's transform and scale
            e->getComponent<Transform>()->scale.x = map.scale;
            e->getComponent<Transform>()->scale.y = map.scale;

            // Set the entity's tag
            e->tag = Tag::tile;

            // Add a sprite component to the entity
            e->addComponent(new Sprite(map.assetId, srcRectX, srcRectY, map.tileSize, map.tileSize, (int)Tag::tile));
            
            // If the collider type is 'C', add a box collider component to the entity
            if (collider == 'C') {
                e->addComponent(new BoxCollider(0, 0, map.tileSize, map.tileSize));
            }
        }
    }

    // Close the map file
    mapFile.close();
}
