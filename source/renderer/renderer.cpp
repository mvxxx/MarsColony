/*
mvxxx 2017
https://github.com/mvxxx
*/

#include "renderer.hpp"


bool Renderer::hasProperBody( std::shared_ptr<std::vector<std::shared_ptr<mv::Entity>>> collection )
{
	return !collection->empty() && (*collection)[0]->hasComponent<ProperBody>();
}

void Renderer::drawAll( sf::RenderWindow& window )
{
	for ( auto& layer : drawLayers )
	{
		for ( auto& collection : layer.second )
		{
			for ( auto& drawableObject : *collection )
			{
				drawableObject->getComponent<ProperBody>()->draw( window );
			}
		}
	}
}

bool Renderer::addCollection( std::shared_ptr<std::vector<std::shared_ptr<mv::Entity>>> collection, layer_t numberOfLayer )
{
	if ( hasProperBody( collection ) )
		drawLayers[numberOfLayer].emplace_back( collection );

	return true;
}
