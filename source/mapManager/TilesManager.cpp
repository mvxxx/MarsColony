/*
mvxxx 2017
https://github.com/mvxxx
*/

#include "TilesManager.hpp"

TilesManager::TilesManager()
{
	cache.get( "data/textures/cellTexture.png" );
}

void TilesManager::manage()
{
	for ( auto& entity : entities )
	{
		UNUSED(entity);
	}
}

void TilesManager::addEntityToManage( std::shared_ptr<mv::Entity> entity )
{
	entities.push_back( entity );
}

void TilesManager::createWorld( const std::string& mapPath )
{
	Loader loader;

	std::unique_ptr<WorldWrapper_t> mapPack = loader.loadMap( mapPath );

	for ( int i = 0; i < mapPack->unitDimensions_x; i++ )
	{
		for ( int j = 0; j < mapPack->unitDimensions_y; j++ )
		{
			addEntityToManage( std::make_shared<Cell>( sf::Vector2f(i * 64.f, j * 64.f ), sf::Vector2f( 64.f, 64.f ), *cache.get( "data/textures/cellTexture.png" ), mapPack->map[j*mapPack->unitDimensions_x + i] ) );
		}
	}
}

std::shared_ptr<std::vector<std::shared_ptr<mv::Entity>>> TilesManager::getTiles()
{
	std::shared_ptr<std::vector<std::shared_ptr<mv::Entity>>> pointerToTiles;

	pointerToTiles.reset( &entities );

	return pointerToTiles;
}
