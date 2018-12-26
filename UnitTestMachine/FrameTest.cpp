#pragma once

#include "pch.h"

#include <../external/include/SFML/Graphics/VertexArray.hpp>

#include "../source/frame/Frame.hpp"
#include "../source/scene/Scene.hpp"

/**
* @brief FrameTest -> Frame.hpp -> basicFuncionallity test
*/
TEST(FrameTest, basicFuncionallity)
{
	Frame fr(std::make_shared<Scene>("title", sf::Vector2f{ 200,200 }));

	EXPECT_TRUE(fr.hasComponent<ProperBody>());
	EXPECT_NO_THROW(fr.getComponent<ProperBody>()->getAs<sf::VertexArray>());
	EXPECT_FALSE(fr.getComponent<ProperBody>()->isVisible());
	EXPECT_EQ(fr.getFrame().getVertexCount(), 8);
}

/**
* @brief FrameTest -> Frame.hpp -> managing selection test
*/
TEST(FrameTest, manageSelection)
{
	Frame fr(std::make_shared<Scene>("title", sf::Vector2f{ 200,200 }));

	fr.activateSelection({ 0,1 });
	fr.updateSelection({ 3,4 });

	EXPECT_EQ(fr.getFrame()[0].position, sf::Vector2f(0, 1));
	EXPECT_EQ(fr.getFrame()[1].position, sf::Vector2f(0, 4));
	EXPECT_EQ(fr.getFrame()[2].position, sf::Vector2f(0, 4));
	EXPECT_EQ(fr.getFrame()[3].position, sf::Vector2f(3, 4));
	EXPECT_EQ(fr.getFrame()[4].position, sf::Vector2f(3, 4));
	EXPECT_EQ(fr.getFrame()[5].position, sf::Vector2f(3, 1));
	EXPECT_EQ(fr.getFrame()[6].position, sf::Vector2f(3, 1));
	EXPECT_EQ(fr.getFrame()[7].position, sf::Vector2f(0, 1));
}