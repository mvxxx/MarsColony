/*
mvxxx 2019
https://github.com/mvxxx
*/

#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <memory>

#include "../wrappers/WorldWrapper.hpp"
/**
* @brief Loader - class currently used for loading map
*/
class Loader
{
	/* ===Objects=== */
public:
protected:
private:
	/* ===Methods=== */
public:

	/**
	* @brief loads map from path
	* @param path - path for data
	* @return unique_ptr for map
	*/
	std::unique_ptr<WorldWrapper_t> loadMap( const std::string& path );

protected:
private:
};
