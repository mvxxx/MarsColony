#pragma once
#include "pch.h"
#include <memory>

#include "../external/include/SFML//System/Vector2.hpp"
#include "../source/Utilities.hpp"
#include "../source/scene/Scene.hpp"

/**
* @brief UtilitiesTest -> Utilities.hpp -> convertToUnitPosition test
*/
TEST(UtilitiesTest, convertToUnitPosition)
{
	sf::Vector2f pxPos = { 100,100 };
	sf::Vector2f cellDim = { 25,25 };

	auto uPos = Utilities::convertToUnitPosition(pxPos, cellDim);
	EXPECT_TRUE(uPos.x == 4);
	EXPECT_TRUE(uPos.y == 4);

	pxPos = { 99,100 };
	uPos = Utilities::convertToUnitPosition(pxPos, cellDim);

	EXPECT_TRUE(uPos.x == 3);
	EXPECT_TRUE(uPos.y == 4);
}

/**
* @brief UtilitiesTest -> Utilities.hpp -> mouseWorldPosition test
*/
TEST(UtilitiesTest, mouseWorldPosition)
{
	//SOON
}

/**
* @brief UtilitiesTest -> Utilities.hpp -> mouseWindowPosition test
*/
TEST(UtilitiesTest, mouseWindowPosition)
{
	//SOON
}

/**
* @brief UtilitiesTest -> Utilities.hpp -> isInWindow test
*/
TEST(UtilitiesTest, isInWindow)
{
	auto scene = std::make_shared<Scene>("GTest", sf::Vector2f(200, 200));
	sf::Vector2f v1 = { 50, 60 };
	sf::Vector2f v2 = { 200,200 };
	sf::Vector2f v3 = { 199,199 };
	sf::Vector2f v4 = { 250,180 };
	sf::Vector2f v5 = { 180,250 };

	EXPECT_TRUE(Utilities::isInWindow(v1, scene));
	EXPECT_FALSE(Utilities::isInWindow(v2, scene));
	EXPECT_TRUE(Utilities::isInWindow(v3, scene));
	EXPECT_FALSE(Utilities::isInWindow(v4, scene));
	EXPECT_FALSE(Utilities::isInWindow(v5, scene));
}