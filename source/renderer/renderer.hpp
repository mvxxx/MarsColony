/*
mvxxx 2017
https://github.com/mvxxx
*/

#pragma once

#include <memory>
#include <vector>
#include <map>

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

	/* ===Methods=== */
public:
	bool addCollection( std::shared_ptr<std::vector<std::shared_ptr<mv::Entity>>> collection, DrawMap::layerID_t numberOfLayer );
	void drawAll( sf::RenderWindow& window );
	bool addSingle( const std::shared_ptr<mv::Entity>& , DrawMap::layerID_t numberOfLayer );

protected:
private:
	bool hasProperBody( std::shared_ptr<std::vector<std::shared_ptr<mv::Entity>>> collection  );
	bool hasProperBody( std::shared_ptr<mv::Entity> entity );
};
