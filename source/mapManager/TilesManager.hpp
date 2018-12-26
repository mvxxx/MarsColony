/*
mvxxx 2017
https://github.com/mvxxx
*/

#pragma once

#include <memory>

#include "../loader/Loader.hpp"
#include "../entities/cell/cell.hpp"
#include "../wrappers/WorldWrapper.hpp"
#include "../cache/Cache.hpp"
#include "../ecs/entity/Entity.hpp"
#include "manager.hpp"

/**
* @brief class of managing tiles
*/
class TilesManager :public Manager<mv::Entity>
{
	/* ===Objects=== */
public:
protected:
private:
	//cache for tile data
	mv::Cache<sf::Texture> cache;
	/* ===Methods=== */
public:
	/**
	* @brief classic ctor
	*/
	TilesManager();

	/**
	* @brief manages all tiles
	*/
	virtual void manage() override;

	/**
	* @brief adds entity to managing loop
	* @param entity - pointer to given object
	*/
	virtual void addEntityToManage( std::shared_ptr<mv::Entity> entity ) override;
	
	/**
	* @brief creates world from path
	* @param mapPath - path to resource
	*/
	void createWorld( const std::string& mapPath );
	
	/**
	* @brief getter for tiles
	* @return shared_ptr to tiles map
	*/
	std::shared_ptr<std::vector<std::shared_ptr<mv::Entity>>> getTiles();

protected:
private:
};
