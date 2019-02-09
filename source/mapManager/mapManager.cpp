#include "mapManager.hpp"

#include <iostream>

MapManager::MapManager()
{
}

void MapManager::createWorld( const std::string& mapPath )
{
	tilesManager.createWorld( mapPath );
}

void MapManager::manageAll()
{
	tilesManager.manage();
}

