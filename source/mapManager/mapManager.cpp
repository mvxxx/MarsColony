#include "mapManager.hpp"

#include <iostream>

MapManager::MapManager()
{
}

void MapManager::createWorld( const std::string& mapPath, CollisionManager& collisionManager )
{
	tilesManager.createWorld( mapPath, collisionManager );
}

void MapManager::manageAll()
{
	(void)[](){};
}

