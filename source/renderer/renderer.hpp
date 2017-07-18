/*
mvxxx 2017
https://github.com/mvxxx
*/

#pragma once

#include <memory>
#include <vector>
#include <map>

#include <SFML/Graphics/Drawable.hpp>
#include "ecs/entity/Entity.hpp"
#include "ecs/component/ProperBody.hpp"
#include "wrappers/DrawMap.hpp"

class Renderer
{
	/* ===Objects=== */
public:
protected:
private:
	DrawMap drawMap;

	enum class drawObjectType_t
	{
		SIMPLE_DRAWABLE,
		PROPER_BODY
	};
	/* ===Methods=== */
public:
	bool addCollection( std::shared_ptr<std::vector<std::shared_ptr<mv::Entity>>> collection, DrawMap::layerID_t numberOfLayer, DrawMap::renderType_t renderType );
	void drawAll( sf::RenderWindow& window , std::shared_ptr<sf::View> defaultView, std::shared_ptr<sf::View> UIView );
	bool addSingle( const std::shared_ptr<mv::Entity>& , DrawMap::layerID_t numberOfLayer, DrawMap::renderType_t renderType );

protected:
private:
	bool isAbleToDraw( std::shared_ptr<std::vector<std::shared_ptr<mv::Entity>>> collection  );
	bool isAbleToDraw( std::shared_ptr<mv::Entity> entity );
};
