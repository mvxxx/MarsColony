/*
mvxxx 2017
https://github.com/mvxxx
*/

#pragma once

#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Mouse.hpp>

#include "scene/Scene.hpp"

#define UNUSED(x) (void)x;

/**
* @brief Most important tools in application
*/
class Utilities
{
	/* ===Objects=== */
public:
protected:
private:
	/* ===Methods=== */
public:
	/**
	* @brief converts data to unit position
	* @param pxPos - pixel position
	* @param cellDim - cell dimensions
	* @return Vector2 with unit position
	*/
	static sf::Vector2i convertToUnitPosition( const sf::Vector2f& pxPos, const sf::Vector2f& cellDim )
	{
		return sf::Vector2i( static_cast<int>(pxPos.x / cellDim.x), static_cast<int>(pxPos.y / cellDim.y) );
	}

	/**
	* @brief calculate mouse world position
	* @param scene pointer (smart)
	* @param viewType - type of view
	* @return returns position of mouse relative to the world
	*/
	static sf::Vector2f mouseWorldPosition( const std::shared_ptr<Scene>& scene, const Scene::viewType_t& viewType )
	{
		return scene->getWindow()->mapPixelToCoords( sf::Mouse::getPosition( *scene->getWindow() ), *(scene->getViews().at(viewType)) );
	}

	/**
	* @brief calculate mouse world position
	* @param scene pointer (raw)
	* @param viewType - type of view
	* @return returns position of mouse relative to the world
	*/
	static sf::Vector2f mouseWorldPosition(Scene* scene, const Scene::viewType_t& viewType)
	{
		return scene->getWindow()->mapPixelToCoords(sf::Mouse::getPosition(*scene->getWindow()), *(scene->getViews().at(viewType)));
	}

	/**
	* @brief calculate mouse window position
	* @param scene pointer (smart)
	* @return returns position of mouse relative to the window
	*/
	static sf::Vector2f mouseWindowPosition( const std::shared_ptr<Scene>& scene )
	{
		return static_cast<sf::Vector2f>(sf::Mouse::getPosition( *scene->getWindow() ));
	}

	/**
	* @brief calculate mouse window position
	* @param scene pointer (raw)
	* @return returns position of mouse relative to the window
	*/
	static sf::Vector2f mouseWindowPosition(Scene* scene)
	{
		return static_cast<sf::Vector2f>(sf::Mouse::getPosition(*scene->getWindow()));
	}

	/**
	* @brief checks if point with given position is in widnow
	* @param pos - position of given point
	* @param scene pointer
	* @return returns true if point with given position is in window, false otherwise
	*/
	static bool isInWindow( const sf::Vector2f& pos, const std::shared_ptr<Scene>& scene )
	{
		return  pos.x*pos.y > 0 && pos.x + pos.y > 0 &&
			pos.x < scene->getWindow()->getSize().x  && pos.y < scene->getWindow()->getSize().y;
	}
protected:
private:
};
