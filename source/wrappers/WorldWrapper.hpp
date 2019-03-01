/*
mvxxx 2019
https://github.com/mvxxx
*/

#pragma once

#include "../../external/SFML/include/SFML/System/Vector2.hpp"
#include "../mapManager/IconManager.hpp"
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


	//in unit system
	sf::Vector2i firstPlayerPosition;
	sf::Vector2i secondPlayerPosition;

	std::vector<std::pair<IconManager::bonus_t,sf::Vector2i>> iconsData;

};
