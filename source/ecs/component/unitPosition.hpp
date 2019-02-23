/*
mvxxx 2019
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
	void update(int x, int y)
	{
		i = static_cast<int>(x / mv::constants::defaults::CELL_DIMENSION.x);
		j = static_cast<int>(y / mv::constants::defaults::CELL_DIMENSION.y);
	}

	void update(const sf::Vector2f& position)
	{
		i = static_cast<int>(position.x / mv::constants::defaults::CELL_DIMENSION.x);
		j = static_cast<int>(position.y / mv::constants::defaults::CELL_DIMENSION.y);
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

	/**
	 * @brief converts unit system pos to vec2i
	 * @return i,j as vec2i
	 */
	sf::Vector2i getAsVec2i()
	{
		return sf::Vector2i{i,j};
	}

protected:
private:
};