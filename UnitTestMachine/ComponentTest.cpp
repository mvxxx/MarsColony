#pragma once

#include "pch.h"

#include "../source/ecs/component/Component.hpp"
#include "../source/ecs/entity/Entity.hpp"

/**
* @brief ComponentTest -> Component.hpp test
*/
TEST(ComponentTest, Component )
{
	auto entity = std::make_shared<mv::Entity>();
	mv::Component c(entity);

	EXPECT_TRUE(*c.getOwner() == *entity);
}