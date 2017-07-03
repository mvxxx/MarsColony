/*
mvxxx 2017
https://github.com/mvxxx
*/

#pragma once

#include <SFML/System/Vector2.hpp>

class Math
{
	/* ===Objects=== */
public:
protected:
private:
	/* ===Methods=== */
public:
	static sf::Vector2i convertToUnitPosition( const sf::Vector2f& pxPos, const sf::Vector2f& cellDim )
	{
		return sf::Vector2i( pxPos.x / cellDim.x, pxPos.y / cellDim.y );
	}
protected:
private:
};