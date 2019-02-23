#include "TilesManager.hpp"

TilesManager::TilesManager()
{
	cache.get( mv::constants::path::CELL_TEXTURE_ATLAS );
}


void TilesManager::addEntityToManage( std::shared_ptr<mv::Entity> entity )
{
	entities.push_back( entity );
}

void TilesManager::createWorld(const WorldWrapper_t& mapPack, CollisionManager& collisionManager  )
{
	for ( int i = 0; i < mapPack.unitDimensions_x; i++ )
	{
		for ( int j = 0; j < mapPack.unitDimensions_y; j++ )
		{
			std::shared_ptr<Cell> currentCell = std::make_shared<Cell>( sf::Vector2f(i * mv::constants::defaults::CELL_DIMENSION.x,
					                                                    j * mv::constants::defaults::CELL_DIMENSION.y),
																		mv::constants::defaults::CELL_DIMENSION,
																		*cache.get( mv::constants::path::CELL_TEXTURE_ATLAS ),
																		mapPack.map[j*mapPack.unitDimensions_x + i] );
			collisionManager.addToCollisionMap(currentCell) ;
			this->addEntityToManage(currentCell);
		}
	}
}

std::shared_ptr<std::vector<std::shared_ptr<mv::Entity>>> TilesManager::getTiles()
{
	std::shared_ptr<std::vector<std::shared_ptr<mv::Entity>>> pointerToTiles;

	pointerToTiles.reset( &entities );

	return pointerToTiles;
}
