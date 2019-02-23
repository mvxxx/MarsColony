#include "mapManager.hpp"

#include <iostream>

MapManager::MapManager()
{
}

void MapManager::createWorld( const WorldWrapper_t& mapPack, CollisionManager& collisionManager )
{
	tilesManager.createWorld( mapPack, collisionManager );
}

