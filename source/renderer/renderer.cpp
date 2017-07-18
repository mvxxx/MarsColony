/*
mvxxx 2017
https://github.com/mvxxx
*/

#include "renderer.hpp"
#include "ecs/component/SimpleDrawable.hpp"


bool Renderer::isAbleToDraw( std::shared_ptr<std::vector<std::shared_ptr<mv::Entity>>> collection )
{
	return !collection->empty() && (*collection)[0]->hasComponent<ProperBody>() || (*collection)[0]->hasComponent<SimpleDrawable>();
}

bool Renderer::isAbleToDraw( std::shared_ptr<mv::Entity> entity )
{
	return entity->hasComponent<ProperBody>() || entity->hasComponent<SimpleDrawable>();
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
				drawObjectType_t objectType = (collection->begin()->get()->hasComponent<ProperBody>() ? drawObjectType_t::PROPER_BODY : drawObjectType_t::SIMPLE_DRAWABLE);

				//This fragment will be refactored in future
				for ( auto& drawableObject : *collection )
				{
					if ( objectType == drawObjectType_t::PROPER_BODY )
					{
						auto properBody = drawableObject->getComponent<ProperBody>();

						if ( properBody->visible )
							window.draw( *properBody );
					}else
					{
						auto simpleDrawable= drawableObject->getComponent<SimpleDrawable>();

						if ( simpleDrawable->visible )
							window.draw( *simpleDrawable );
					}
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
