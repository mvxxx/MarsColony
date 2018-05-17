/*
mvxxx 2017
https://github.com/mvxxx
*/

#include "renderer.hpp"


bool Renderer::isAbleToDraw( std::shared_ptr<std::vector<std::shared_ptr<mv::Entity>>> collection )
{
	return !collection->empty() && (*collection)[0]->hasComponent<ProperBody>();
}

bool Renderer::isAbleToDraw( std::shared_ptr<mv::Entity> entity )
{
	return entity->hasComponent<ProperBody>();
}

void Renderer::drawAll( sf::RenderWindow& window, std::shared_ptr<sf::View> defaultView, std::shared_ptr<sf::View> UIView )
{
	for ( auto& layerPack : drawMap.layerPackData )
	{
		if ( layerPack.first == DrawMap::renderType_t::UI )
			window.setView( *UIView );
		else window.setView( *defaultView );

		for ( auto& layer : layerPack.second )
		{
			for ( auto& collection : layer.second )
			{
				for ( auto& drawableObject : *collection )
				{
						auto properBody = drawableObject->getComponent<ProperBody>();

						if ( properBody->isVisible() )
							window.draw( *properBody );
				}
			}
		}
	}
}

bool Renderer::addSingle( const std::shared_ptr<mv::Entity>& entity, DrawMap::layerID_t numberOfLayer, DrawMap::renderType_t renderType )
{
	if ( isAbleToDraw( entity ) )
	{
		auto tempCollection = std::make_shared<std::vector<std::shared_ptr<mv::Entity>>>();
		tempCollection->push_back( entity );
		drawMap.layerPackData[renderType][numberOfLayer].push_back( tempCollection );
	}

	return true;
}

bool Renderer::addCollection( std::shared_ptr<std::vector<std::shared_ptr<mv::Entity>>> collection, DrawMap::layerID_t numberOfLayer, DrawMap::renderType_t renderType )
{
	if ( isAbleToDraw( collection ) )
		drawMap.layerPackData[renderType][numberOfLayer].push_back( collection );

	return true;
}
