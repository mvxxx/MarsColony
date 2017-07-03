/*
mvxxx 2017
https://github.com/mvxxx
*/

#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <memory>

#include "wrappers/WorldWrapper.hpp"

class Loader
{
	/* ===Objects=== */
public:
protected:
private:
	/* ===Methods=== */
public:

	std::unique_ptr<WorldWrapper_t> loadMap( const std::string& path );

protected:
private:
};
