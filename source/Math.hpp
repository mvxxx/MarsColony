/*
mvxxx 2017
https://github.com/mvxxx
*/

#pragma once

#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Mouse.hpp>

#include "scene/Scene.hpp"

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

	static sf::Vector2f mouseWorldPosition( std::shared_ptr<Scene> scene )
	{
		return scene->getWindow()->mapPixelToCoords( sf::Mouse::getPosition( *scene->getWindow() ) );
	}

	static sf::Vector2f mouseWindowPosition( std::shared_ptr<Scene> scene )
	{
		return static_cast<sf::Vector2f>(sf::Mouse::getPosition( *scene->getWindow() ));
	}
protected:
private:
};
