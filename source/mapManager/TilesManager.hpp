/*
mvxxx 2017
https://github.com/mvxxx
*/

#pragma once

#include <memory>

#include "loader/Loader.hpp"
#include "entities/cell/cell.hpp"
#include "wrappers/WorldWrapper.hpp"
#include "cache/Cache.hpp"
#include "ecs/entity/entity.hpp"

#include "manager.hpp"


class TilesManager :public Manager<mv::Entity>
{
	/* ===Objects=== */
public:
protected:
private:
	mv::Cache<sf::Texture> cache;
	/* ===Methods=== */
public:
	TilesManager();
	virtual void manage() override;
	virtual void addEntityToManage( std::shared_ptr<mv::Entity> entity ) override;
	void createWorld( const std::string& mapPath );
	
	std::shared_ptr<std::vector<std::shared_ptr<mv::Entity>>> getTiles();

protected:
private:
};
