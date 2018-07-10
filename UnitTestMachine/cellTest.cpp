#pragma once
#include "pch.h"

#include "../source/entities/cell/cell.hpp"
#include "../source/cache/Cache.hpp"
#include "../source/Utilities.hpp"

/**
* @brief CellTest -> CellTest.hpp -> basicFuncionallity test
*/
TEST(CellTest, basicFuncionallity)
{
	mv::Cache<sf::Texture> cache;
	Cell cell(sf::Vector2f(100,50), sf::Vector2f(64.f, 64.f), *cache.get("../data/textures/cellTexture.png"),0);

	EXPECT_TRUE(cell.hasComponent<UnitPosition>());
	EXPECT_TRUE(cell.hasComponent<ProperBody>());
	EXPECT_EQ(cell.getComponent<ProperBody>()->getAs<sf::Sprite>().getPosition().x, 100);
	EXPECT_EQ(cell.getComponent<ProperBody>()->getAs<sf::Sprite>().getPosition().y, 50);
	EXPECT_EQ(cell.getComponent<ProperBody>()->getAs<sf::Sprite>().getGlobalBounds().width, 64.f);
	EXPECT_EQ(cell.getComponent<ProperBody>()->getAs<sf::Sprite>().getGlobalBounds().height, 64.f);
	EXPECT_EQ(cell.getComponent<UnitPosition>()->i, Utilities::convertToUnitPosition({ 100,50 }, { 64.f,64.f}).x);
	EXPECT_EQ(cell.getComponent<UnitPosition>()->j, Utilities::convertToUnitPosition({ 100,50 }, { 64.f,64.f }).y);
}