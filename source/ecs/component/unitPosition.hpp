/*
mvxxx 2017
https://github.com/mvxxx
*/

#pragma once

#include <SFML/System/Vector2.hpp>

class UnitPosition
{
	/* ===Objects=== */
public:
	int i;
	int j;
protected:
private:
	/* ===Methods=== */
public:
	void update(int x, int y, sf::Vector2f cellDimensions)
	{
		i = static_cast<int>(x / cellDimensions.x);
		j = static_cast<int>(y / cellDimensions.y);
	}

	void setUnitPosition(sf::Vector2i pos)
	{
		i = pos.x;
		j = pos.y;
	}

protected:
private:
};