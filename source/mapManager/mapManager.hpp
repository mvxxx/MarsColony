/*
mvxxx 2019
https://github.com/mvxxx
*/
#pragma once

#include "TilesManager.hpp"
#include "manager.hpp"

/**
* @brief manager for map
*/
class MapManager
{
	/* ===Objects=== */
public:
	//manager of tiles
	TilesManager tilesManager;
protected:
private:
	/* ===Methods=== */
public:
	/**
	* @brief classic ctor
	*/
	MapManager();

	/**
	* @brief creates world from path
	* @param mapPath - path to resource
	*/
	void createWorld(const std::string& mapPath);

	/**
	* @brief manages all tiles
	*/
	void manageAll();
protected:
private:
};

