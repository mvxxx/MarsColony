#pragma once
#include "pch.h"

#include "../source/ecs/entity/Entity.hpp"

/**
* @Brief EntityTest -> Entity.hpp ->comparisonOperator test
*/
TEST(EntityTest, comparisonOperator)
{
	mv::Entity first;
	mv::Entity second;

	EXPECT_TRUE(first == second);

	first.addComponent<int>();
	EXPECT_FALSE(first == second);

	second.addComponent<int>();
	EXPECT_TRUE(first == second);

	first.addComponent<float>();
	first.addComponent<char>();
	second.addComponent<char>();
	second.addComponent<float>();
	EXPECT_TRUE(first == second);
}

/**
* @Brief EntityTest -> Entity.hpp ->moveCtor test
*/
TEST(EntityTest, moveCtor)
{
	mv::Entity first;

	first.addComponent<int>();
	*first.getComponent<int>() = 10;

	EXPECT_EQ(*first.getComponent<int>(), 10);

	mv::Entity second(std::move(first));

	EXPECT_EQ(*second.getComponent<int>(), 10);
	EXPECT_EQ(first.getComponent<int>(), nullptr);
}


/**
* @Brief EntityTest -> Entity.hpp ->copyCtor test
*/
TEST(EntityTest, copyCtor)
{
	mv::Entity first;

	first.addComponent<int>();
	*first.getComponent<int>() = 10;

	EXPECT_EQ(*first.getComponent<int>(), 10);

	mv::Entity second(first);

	EXPECT_EQ(*second.getComponent<int>(), 10);
	EXPECT_TRUE(first.getComponent<int>() != nullptr );
	EXPECT_EQ(*first.getComponent<int>(), 10);
}

/**
* @Brief EntityTest -> Entity.hpp ->moveAssignmentOperator test
*/
TEST(EntityTest, moveAssignmentOperator)
{
	mv::Entity first;

	first.addComponent<int>();
	*first.getComponent<int>() = 10;

	EXPECT_EQ(*first.getComponent<int>(), 10);

	mv::Entity second = std::move(first);

	EXPECT_EQ(*second.getComponent<int>(), 10);
	EXPECT_EQ(first.getComponent<int>(), nullptr);
}

/**
* @Brief EntityTest -> Entity.hpp ->copy assignment operator test
*/
TEST(EntityTest, copyAssignmentOperator)
{
	mv::Entity first;

	first.addComponent<int>();
	*first.getComponent<int>() = 10;

	EXPECT_EQ(*first.getComponent<int>(), 10);

	mv::Entity second = first;

	EXPECT_EQ(*second.getComponent<int>(), 10);
	EXPECT_TRUE(first.getComponent<int>() != nullptr);
	EXPECT_EQ(*first.getComponent<int>(), 10);
}

/**
* @Brief EntityTest -> Entity.hpp ->getComponent test
*/
TEST(EntityTest, getComponent)
{
	mv::Entity entity;
	entity.addComponent<int>();
	*entity.getComponent<int>() = 10;
	EXPECT_EQ(*entity.getComponent<int>(), 10);
	*entity.getComponent<int>() = 15;
	EXPECT_EQ(*entity.getComponent<int>(), 15);
}

/**
* @Brief EntityTest -> Entity.hpp ->addComponent test
*/
TEST(EntityTest, addComponent)
{
	mv::Entity entity;
	EXPECT_FALSE(entity.hasComponent<int>());
	entity.addComponent<int>();
	EXPECT_TRUE(entity.hasComponent<int>());
}

/**
* @Brief EntityTest -> Entity.hpp ->removeComponent test
*/
TEST(EntityTest, removeComponent)
{
	mv::Entity entity;
	EXPECT_FALSE(entity.hasComponent<int>());
	EXPECT_EQ(entity.getComponent<int>(), nullptr);
	entity.addComponent<int>();

	EXPECT_TRUE(entity.hasComponent<int>());
	EXPECT_FALSE(entity.getComponent<int>() == nullptr);

	entity.removeComponent<int>();
	EXPECT_FALSE(entity.hasComponent<int>());
	EXPECT_EQ(entity.getComponent<int>(), nullptr);
}

/**
* @Brief EntityTest -> Entity.hpp ->hasComponent test
*/
TEST(EntityTest, hasComponent)
{
	mv::Entity entity;
	EXPECT_FALSE(entity.hasComponent<int>());
	EXPECT_EQ(entity.getComponent<int>(), nullptr);
	entity.addComponent<int>();

	EXPECT_TRUE(entity.hasComponent<int>());
	EXPECT_FALSE(entity.getComponent<int>() == nullptr);
}
