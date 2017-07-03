/*
mvxxx 2017
https://github.com/mvxxx
*/

#pragma once

#include "TilesManager.hpp"
#include "manager.hpp"

class MapManager
{
	/* ===Objects=== */
public:
	TilesManager tilesManager;
protected:
private:
	/* ===Methods=== */
public:
	MapManager();

	void createWorld(const std::string& mapPath);

	void manageAll();
protected:
private:
};

