/*
mvxxx 2017
https://github.com/mvxxx
*/

#pragma once

#include "../../../external/SFML/include/SFML/System/Vector2.hpp"

/**
* @brief class to represents unit position
*/
class UnitPosition
{
	/* ===Objects=== */
public:
	//x
	int i;

	//y
	int j;
protected:
private:
	/* ===Methods=== */
public:
	/**
	* @brief draws object
	* @param x - x coordinate
	* @param y - y coordinate
	* @param cellDimensions cell dimensions
	*/
	void update(int x, int y, sf::Vector2f cellDimensions)
	{
		i = static_cast<int>(x / cellDimensions.x);
		j = static_cast<int>(y / cellDimensions.y);
	}

	/**
	* @brief sets position
	* @param pos - coordinates ( in unit system )
	*/
	void setUnitPosition(sf::Vector2i pos)
	{
		i = pos.x;
		j = pos.y;
	}

protected:
private:
};