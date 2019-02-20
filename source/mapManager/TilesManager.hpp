/*
mvxxx 2019
https://github.com/mvxxx
*/

#pragma once

#include <memory>

#include "../loader/Loader.hpp"
#include "../entities/cell/cell.hpp"
#include "../wrappers/WorldWrapper.hpp"
#include "../cache/Cache.hpp"
#include "../ecs/entity/Entity.hpp"
#include "CollisionManager.hpp"
#include "manager.hpp"

/**
* @brief class for managing tiles in the background
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
	* @brief adds entity to managing loop
	* @param entity - pointer to given object
	*/
	virtual void addEntityToManage( std::shared_ptr<mv::Entity> entity ) override;
	
	/**
	* @brief creates world from path
	* @param mapPath - path to resource
	* @param collisionManager - manager of collision events
	*/
	void createWorld( const std::string& mapPath, CollisionManager& collisionManager );
	
	/**
	* @brief getter for tiles
	* @return shared_ptr to tiles map
	*/
	std::shared_ptr<std::vector<std::shared_ptr<mv::Entity>>> getTiles();

protected:
private:
};
