#pragma once
#include "pch.h"
#include "../source/cache/Cache.hpp"

#include <SFML/Graphics/Texture.hpp>

/**
* @brief CacheTest -> Cache.hpp -> get test test
*/
TEST(CacheTest, get)
{
	mv::Cache<sf::Texture> cache;
	std::shared_ptr<sf::Texture> ptr = cache.get("../data/textures/unitTest.png");
	EXPECT_EQ(ptr->getSize(), sf::Vector2u(35,35));
}