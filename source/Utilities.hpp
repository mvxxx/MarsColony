/*
mvxxx 2019
https://github.com/mvxxx
*/

#pragma once

#include "../external/SFML/include/SFML/System/Vector2.hpp"
#include "../external/SFML/include/SFML/Window/Mouse.hpp"

#include "scene/Scene.hpp"

#include <cmath>

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
	static sf::Vector2i convertToUnitPosition( const sf::Vector2f& pxPos)
	{
		return sf::Vector2i( static_cast<int>(pxPos.x / mv::constants::defaults::CELL_DIMENSION.x),
				             static_cast<int>(pxPos.y / mv::constants::defaults::CELL_DIMENSION.y));
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

	/**
	 * @brief converts radian to
	 * @param radian - angle in radians
	 * @return angle in degrees
	 */
	static float radianToDegree(float radian)
	{
	 	return radian * (180.f/static_cast<float>(M_PI));
	}

	/**
	 * @brief Calculate length of given vector
	 * @warning uses standard scalar product
	 * @return length as float
	 */
	static float lengthOfVector(const sf::Vector2f& vec)
	{
		return std::sqrt(vec.x*vec.x + vec.y*vec.y);
	}

	/**
	 * @brief Calculate angle between vectors
	 * @param first vector to calculation
	 * @param second vector to calculation
	 * @warning uses standard scalar product
	 * @return angle as degrees
	 */
	static float angleBetweenVectors(const sf::Vector2f& first, const sf::Vector2f& second)
	{
		return radianToDegree(std::acos(first.x*second.x + first.y*second.y/(lengthOfVector(first)*lengthOfVector(second))));
	}

	/**
	 * @param p - first logical value
	 * @param q - second logical value
	 * @return p --> q
	 */
	static bool logicalImplication(bool p, bool q)
	{
		return !p || q;
	}
protected:
private:
};
