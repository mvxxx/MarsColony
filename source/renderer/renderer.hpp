/*
mvxxx 2017
https://github.com/mvxxx
*/

#pragma once

#include <memory>
#include <vector>
#include <map>

#include "../../external/SFML/include/SFML/Graphics/Drawable.hpp"

#include "../ecs/entity/Entity.hpp"
#include "../ecs/component/ProperBody.hpp"
#include "../wrappers/DrawMap.hpp"
#include "../logger/Logger.hpp"

/**
* @brief class for rendering layers of textures
*/
class Renderer
{
	/* ===Objects=== */
public:
protected:
private:
	//draw map - see wrapper
	DrawMap drawMap;

	/**
	* @brief type of drawable object
	*/
	enum class drawObjectType_t
	{
		SIMPLE_DRAWABLE,
		PROPER_BODY
	};
	/* ===Methods=== */
public:
	/**
	* @brief adds collection to drawMap
	* @param collection of data
	* @param numberOfLayer - layer's number where collection will be added
	* @param renderType - type of rendering
	* @see renderType_t
	* @return true if collection has been added, false otherwise
	*/
	bool addCollection( std::shared_ptr<std::vector<std::shared_ptr<mv::Entity>>> collection, DrawMap::layerID_t numberOfLayer, DrawMap::renderType_t renderType );
	
	/**
	* @brief draws all entities
	* @param window from SFML
	* @param defaultView - default view which is used during rendering
	* @param UIView - UI view which is used during rendering
	*/
	void drawAll( sf::RenderWindow& window , std::shared_ptr<sf::View> defaultView, std::shared_ptr<sf::View> UIView );
	
	/**
	* @brief adds single object to drawMap
	* @param collection of data
	* @param numberOfLayer - layer's number where object will be added
	* @param renderType - type of rendering
	* @see renderType_t
	* @return true if collection has been added, false otherwise
	*/
	bool addSingle( const std::shared_ptr<mv::Entity>& , DrawMap::layerID_t numberOfLayer, DrawMap::renderType_t renderType );

protected:
private:

	/**
	* @brief checks if collection is able to be drawn
	* @param collection to check
	* @return true if it can, false otherwise
	*/
	bool isAbleToDraw( std::shared_ptr<std::vector<std::shared_ptr<mv::Entity>>> collection  );

	/**
	* @brief checks if entity is able to be drawn
	* @param entity to check
	* @return true if it can, false otherwise
	*/
	bool isAbleToDraw( std::shared_ptr<mv::Entity> entity );
};
