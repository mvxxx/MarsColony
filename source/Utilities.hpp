/*
mvxxx 2017
https://github.com/mvxxx
*/

#pragma once

#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Mouse.hpp>

#include "scene/Scene.hpp"

#define UNUSED(x) (void)x;

class Utilities
{
	/* ===Objects=== */
public:
protected:
private:
	/* ===Methods=== */
public:
	static sf::Vector2i convertToUnitPosition( const sf::Vector2f& pxPos, const sf::Vector2f& cellDim )
	{
		return sf::Vector2i( static_cast<int>(pxPos.x / cellDim.x), static_cast<int>(pxPos.y / cellDim.y) );
	}

	static sf::Vector2f mouseWorldPosition( const std::shared_ptr<Scene>& scene, const Scene::viewType_t& viewType )
	{
		return scene->getWindow()->mapPixelToCoords( sf::Mouse::getPosition( *scene->getWindow() ), *(scene->getViews().at(viewType)) );
	}

	static sf::Vector2f mouseWorldPosition(Scene* scene, const Scene::viewType_t& viewType)
	{
		return scene->getWindow()->mapPixelToCoords(sf::Mouse::getPosition(*scene->getWindow()), *(scene->getViews().at(viewType)));
	}

	static sf::Vector2f mouseWindowPosition( const std::shared_ptr<Scene>& scene )
	{
		return static_cast<sf::Vector2f>(sf::Mouse::getPosition( *scene->getWindow() ));
	}

	static sf::Vector2f mouseWindowPosition(Scene* scene)
	{
		return static_cast<sf::Vector2f>(sf::Mouse::getPosition(*scene->getWindow()));
	}

	static bool isInWindow( const sf::Vector2f& pos, const std::shared_ptr<Scene>& scene )
	{
		return  pos.x*pos.y > 0 && pos.x + pos.y > 0 &&
			pos.x < scene->getWindow()->getSize().x  && pos.y < scene->getWindow()->getSize().y;
	}
protected:
private:
};
