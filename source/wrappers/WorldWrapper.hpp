/*
mvxxx 2019
https://github.com/mvxxx
*/

#pragma once

#include <vector>

/**
* @brief wrapper for world data
*/
struct WorldWrapper_t
{
	//dimensions of x-coordinate
	int unitDimensions_x;

	//dimensions of y-coordinate
	int unitDimensions_y;

	//map represented by numbers
	std::vector<int> map;
};
